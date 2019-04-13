﻿// -*- C++ -*-
/*!
 * @file  DynamicInPortTest.h
 * @brief DynamicInPort test component
 * @date  $Date$
 *
 * @author 佐々木毅 (Takeshi SASAKI)
 * sasaki-t(_at_)ieee.org
 *
 * $Id$
 */

#ifndef DYNAMICINPORTTEST_H
#define DYNAMICINPORTTEST_H

#include <rtm/idl/BasicDataTypeSkel.h>
#include <rtm/idl/ExtendedDataTypesSkel.h>
#include <rtm/idl/InterfaceDataTypesSkel.h>

// Service implementation headers
// <rtc-template block="service_impl_h">

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="consumer_stub_h">
#include "BasicDataTypeStub.h"

// </rtc-template>

// Service Consumer stub headers
// <rtc-template block="port_stub_h">
// </rtc-template>

#include <rtm/Manager.h>
#include <rtm/DataFlowComponentBase.h>
#include <rtm/CorbaPort.h>
#include <rtm/DataInPort.h>
#include <rtm/DataOutPort.h>

#include "../../../dynamic_port.hpp"

using namespace RTC;

/*!
 * @class DynamicInPortTest
 * @brief DynamicInPort test component
 *
 * 動的入力ポートのプログラム例および動作テスト用コンポーネント。
 * アクティブ状態で入力ポートのInPortManipに文字列が入力されると、
 * それに応じて動的入力ポートの追加と削除を行う。
 * 入力ポートのInPortManipに入力された文字列が数字のみの場合、その
 * 数字の番号の入力ポートがあればそのポートを削除する。
 * 入力ポートのInPortManipに入力された文字列に数字以外の文字が含ま
 * れていた場合、その文字数だけポートを追加する。
 * 動的入力ポートStringDataに入力があった場合、そのポートの名前、番
 * 号と文字列をコンソールに出力する。
 * 非アクティブ化するとすべての動的入力ポートを削除する。
 *
 * InPort
 * ポート名/型/説明
 * InPortManip/TimedString/動的入力ポートの追加・削除コマンド。
 * StringData/DynamicInPort<TimedString>/コンソールに出力する文字列
 * データ。
 *
 */
class DynamicInPortTest
  : public RTC::DataFlowComponentBase
{
 public:
  /*!
   * @brief constructor
   * @param manager Maneger Object
   */
  DynamicInPortTest(RTC::Manager* manager);

  /*!
   * @brief destructor
   */
  ~DynamicInPortTest();

  // <rtc-template block="public_attribute">
  
  // </rtc-template>

  // <rtc-template block="public_operation">
  
  // </rtc-template>

  /***
   *
   * The initialize action (on CREATED->ALIVE transition)
   * formaer rtc_init_entry() 
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onInitialize();

  /***
   *
   * The finalize action (on ALIVE->END transition)
   * formaer rtc_exiting_entry()
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onFinalize();

  /***
   *
   * The startup action when ExecutionContext startup
   * former rtc_starting_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onStartup(RTC::UniqueId ec_id);

  /***
   *
   * The shutdown action when ExecutionContext stop
   * former rtc_stopping_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onShutdown(RTC::UniqueId ec_id);

  /***
   * 初期化を行う。
   *
   * The activated action (Active state entry action)
   * former rtc_active_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onActivated(RTC::UniqueId ec_id);

  /***
   * 動的入力ポートを全て削除する。
   *
   * The deactivated action (Active state exit action)
   * former rtc_active_exit()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onDeactivated(RTC::UniqueId ec_id);

  /***
   * 動的入出力ポートの追加と削除を行う。
   * 入力ポートのInPortManipに入力された文字列が数字のみの場合、そ
   * の数字の番号の入力ポートがあればそのポートを削除する。
   * 入力ポートのInPortManipに入力された文字列に数字以外の文字が含
   * まれていた場合、その文字数だけポートを追加する。
   * 動的入力ポートStringDataに入力があった場合、そのポートの名前、
   * 番号と文字列をコンソールに出力する。
   *
   * The execution action that is invoked periodically
   * former rtc_active_do()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onExecute(RTC::UniqueId ec_id);

  /***
   * 動的入力ポートを全て削除する。
   *
   * The aborting action when main logic error occurred.
   * former rtc_aborting_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
   virtual RTC::ReturnCode_t onAborting(RTC::UniqueId ec_id);

  /***
   *
   * The error action in ERROR state
   * former rtc_error_do()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onError(RTC::UniqueId ec_id);

  /***
   *
   * The reset action that is invoked resetting
   * This is same but different the former rtc_init_entry()
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onReset(RTC::UniqueId ec_id);
  
  /***
   *
   * The state update action that is invoked after onExecute() action
   * no corresponding operation exists in OpenRTm-aist-0.2.0
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onStateUpdate(RTC::UniqueId ec_id);

  /***
   *
   * The action that is invoked when execution context's rate is changed
   * no corresponding operation exists in OpenRTm-aist-0.2.0
   *
   * @param ec_id target ExecutionContext Id
   *
   * @return RTC::ReturnCode_t
   * 
   * 
   */
  // virtual RTC::ReturnCode_t onRateChanged(RTC::UniqueId ec_id);


 protected:
  // <rtc-template block="protected_attribute">
  
  // </rtc-template>

  // <rtc-template block="protected_operation">
  
  // </rtc-template>

  // Configuration variable declaration
  // <rtc-template block="config_declare">

  // </rtc-template>

  // DataInPort declaration
  // <rtc-template block="inport_declare">
  RTC::TimedString m_InPortManip;
  /*!
   * 動的入出力ポートの追加と削除を行う。
   * 入力された文字列が数字のみの場合、その数字の番号の入力ポートが
   * あればそのポートを削除する。
   * 入力された文字列に数字以外の文字が含まれていた場合、その文字数
   * だけポートを追加する。
   * - Type: TimedString
   * - Number: データに依存
   */
  InPort<RTC::TimedString> m_InPortManipIn;
  /*!
   * コンソールに出力する文字列データ。
   * - Type: DynamicInPort<TimedString>
   * - Number: データに依存
   */
  DynamicInPort<RTC::TimedString> m_StringDataIn;
  
  // </rtc-template>


  // DataOutPort declaration
  // <rtc-template block="outport_declare">
  
  // </rtc-template>

  // CORBA Port declaration
  // <rtc-template block="corbaport_declare">
  
  // </rtc-template>

  // Service declaration
  // <rtc-template block="service_declare">
  
  // </rtc-template>

  // Consumer declaration
  // <rtc-template block="consumer_declare">
  
  // </rtc-template>

 private:
  // <rtc-template block="private_attribute">
  
  // </rtc-template>

  // <rtc-template block="private_operation">
  
  // </rtc-template>

};


extern "C"
{
  DLL_EXPORT void DynamicInPortTestInit(RTC::Manager* manager);
};

#endif // DYNAMICINPORTTEST_H
