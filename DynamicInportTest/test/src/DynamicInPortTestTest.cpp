// -*- C++ -*-
/*!
 * @file  DynamicInPortTestTest.cpp
 * @brief DynamicInPort test component
 * @date $Date$
 *
 * @author 佐々木毅 (Takeshi SASAKI)
 * sasaki-t(_at_)ieee.org
 *
 * $Id$
 */

#include "DynamicInPortTestTest.h"

// Module specification
// <rtc-template block="module_spec">
static const char* dynamicinporttest_spec[] =
  {
    "implementation_id", "DynamicInPortTestTest",
    "type_name",         "DynamicInPortTestTest",
    "description",       "DynamicInPort test component",
    "version",           "1.0.0",
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
DynamicInPortTestTest::DynamicInPortTestTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_InPortManipIn("InPortManip", m_InPortManip),
    m_StringDataIn("StringData", m_StringData)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
DynamicInPortTestTest::~DynamicInPortTestTest()
{
}



RTC::ReturnCode_t DynamicInPortTestTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("InPortManip", m_InPortManipOut);
  addOutPort("StringData", m_StringDataOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t DynamicInPortTestTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t DynamicInPortTestTest::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t DynamicInPortTestTest::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*!
 * 初期化を行う。
 */

RTC::ReturnCode_t DynamicInPortTestTest::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*!
 * 動的入力ポートを全て削除する。
 */

RTC::ReturnCode_t DynamicInPortTestTest::onDeactivated(RTC::UniqueId ec_id)
{
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

RTC::ReturnCode_t DynamicInPortTestTest::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*!
 * 動的入力ポートを全て削除する。
 */

RTC::ReturnCode_t DynamicInPortTestTest::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t DynamicInPortTestTest::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t DynamicInPortTestTest::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t DynamicInPortTestTest::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t DynamicInPortTestTest::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void DynamicInPortTestTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(dynamicinporttest_spec);
    manager->registerFactory(profile,
                             RTC::Create<DynamicInPortTestTest>,
                             RTC::Delete<DynamicInPortTestTest>);
  }
  
};


