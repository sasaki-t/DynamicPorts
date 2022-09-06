// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  DynamicInPortTest.cpp
 * @brief DynamicInPort test component
 *
 * @author 佐々木毅 (Takeshi SASAKI)
 * sasaki-t(_at_)ieee.org
 *
 */
// </rtc-template>

#include "DynamicInPortTest.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const dynamicinporttest_spec[] =
#else
static const char* dynamicinporttest_spec[] =
#endif
  {
    "implementation_id", "DynamicInPortTest",
    "type_name",         "DynamicInPortTest",
    "description",       "DynamicInPort test component",
    "version",           "1.1.0",
    "vendor",            "TakeshiSasaki",
    "category",          "example",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
DynamicInPortTest::DynamicInPortTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_InPortManipIn("InPortManip", m_InPortManip),
	m_StringDataIn("StringData")
    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
DynamicInPortTest::~DynamicInPortTest()
{
}



RTC::ReturnCode_t DynamicInPortTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
	addInPort("InPortManip", m_InPortManipIn);
  
  // Set OutPort buffer

  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>

  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t DynamicInPortTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t DynamicInPortTest::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t DynamicInPortTest::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}

/*!
 * 初期化を行う。
 */

RTC::ReturnCode_t DynamicInPortTest::onActivated(RTC::UniqueId /*ec_id*/)
{
	while (m_InPortManipIn.isNew()) {
		m_InPortManipIn.read();
	}

	return RTC::RTC_OK;
}

/*!
 * 動的入力ポートを全て削除する。
 */

RTC::ReturnCode_t DynamicInPortTest::onDeactivated(RTC::UniqueId /*ec_id*/)
{
	//delete port... put removeInPort() first!!
	while (m_StringDataIn.getSize() > 0) {
		// std::cerr << "Port No." << m_StringDataIn.getSize() - 1 << " deleted" << std::endl;
		removeInPort(m_StringDataIn.m_port[m_StringDataIn.getSize() - 1]);
		m_StringDataIn.deletePort(m_StringDataIn.getSize() - 1);
	}

	return RTC::RTC_OK;
}

/*!
 * 動的入出力ポートの追加と削除を行う。
 * 入力ポートのInPortManipに入力された文字列が数字のみの場合、その
 * 数字の番号の入力ポートがあればそのポートを削除する。
 * 入力ポートのInPortManipに入力された文字列に数字以外の文字が含ま
 * れていた場合、その文字数だけポートを追加する。
 * 動的入力ポートStringDataに入力があった場合、そのポートの名前、番
 * 号と文字列をコンソールに出力する。
 */

RTC::ReturnCode_t DynamicInPortTest::onExecute(RTC::UniqueId /*ec_id*/)
{
	unsigned int i;
	int count = 0;
	int res;

	std::string msg;


	// ------- get new data from InPortManip in order to add or delete DynamicInorts  ----------------------------- //
	if (m_InPortManipIn.isNew()) {  //new data comes
		m_InPortManipIn.read();
		msg = m_InPortManip.data;

		if (!msg.empty()) {
			if (msg.find_first_not_of("1234567890") != std::string::npos) { //if a character is not a number -> add msg.size() ports
				std::cerr << "Try to add " << msg.size() << " ports... " << std::flush;

				for (i = 0; i < msg.size(); i++) {
					res = m_StringDataIn.addPort();
					if (res == 0) {
						addInPort(m_StringDataIn.getName(m_StringDataIn.getSize() - 1), m_StringDataIn.m_port[m_StringDataIn.getSize() - 1]);
						m_StringDataIn.m_port[m_StringDataIn.getSize() - 1].read();
						count++;
					}
				}
				std::cerr << count << " ports added" << std::endl;
			}
			else { //only numbers -> delete a port if the corresponding port exists
				i = (unsigned int)std::atoi(msg.c_str());
				if (i < m_StringDataIn.getSize()) { //delete port
					removeInPort(m_StringDataIn.m_port[i]);
					m_StringDataIn.deletePort(i);
					std::cerr << "Port No." << i << " deleted" << std::endl;
				}
				else {
					std::cerr << "Input number " << i << " is greater than port size. No port deleted." << std::endl;
				}
			}
		}
	}

	// ------- get new data from dynamic InPorts ----------------------------- //
	for (i = 0; i < m_StringDataIn.getSize(); i++) {
		if (m_StringDataIn.m_port[i].isNew()) {  //new data comes
		  //read data from InPort
			m_StringDataIn.m_port[i].read();

			msg = m_StringDataIn.m_data[i].data;

			//output to console
			std::cerr << "Port name: " << m_StringDataIn.getName(i) << std::endl;
			std::cerr << "Port number: " << i << std::endl;
			std::cerr << "Message: " << msg << std::endl;
		}
	}

	return RTC::RTC_OK;
}

/*!
 * 動的入力ポートを全て削除する。
 */

RTC::ReturnCode_t DynamicInPortTest::onAborting(RTC::UniqueId /*ec_id*/)
{
	//delete port... put removeInPort() first!!
	while (m_StringDataIn.getSize() > 0) {
		// std::cerr << "Port No." << m_StringDataIn.getSize() - 1 << " deleted" << std::endl;
		removeInPort(m_StringDataIn.m_port[m_StringDataIn.getSize() - 1]);
		m_StringDataIn.deletePort(m_StringDataIn.getSize() - 1);
	}

	return RTC::RTC_OK;
}


//RTC::ReturnCode_t DynamicInPortTest::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t DynamicInPortTest::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t DynamicInPortTest::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t DynamicInPortTest::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}



extern "C"
{
 
  void DynamicInPortTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(dynamicinporttest_spec);
    manager->registerFactory(profile,
                             RTC::Create<DynamicInPortTest>,
                             RTC::Delete<DynamicInPortTest>);
  }
  
}
