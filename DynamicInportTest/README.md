# DynamicInPortTest

## Overview

DynamicInPort test component

## Description

動的入力ポートのプログラム例および動作テスト用コンポーネント。<br/>アクティブ状態で入力ポートのInPortManipに文字列が入力されると、それに応じて動的入力ポートの追加と削除を行う。<br/>入力ポートのInPortManipに入力された文字列が数字のみの場合、その数字の番号の入力ポートがあればそのポートを削除する。<br/>入力ポートのInPortManipに入力された文字列に数字以外の文字が含まれていた場合、その文字数だけポートを追加する。<br/>動的入力ポートStringDataに入力があった場合、そのポートの名前、番号と文字列をコンソールに出力する。<br/>非アクティブ化するとすべての動的入力ポートを削除する。

### Input and Output

InPort<br/>ポート名/型/説明<br/>InPortManip/TimedString/動的入力ポートの追加・削除コマンド。<br/>StringData/DynamicInPort<TimedString>/コンソールに出力する文字列データ。

### Algorithm etc



### Basic Information

|  |  |
----|---- 
| Module Name | DynamicInPortTest |
| Description | DynamicInPort test component |
| Version | 1.1.0 |
| Vendor | TakeshiSasaki |
| Category | example |
| Comp. Type | STATIC |
| Act. Type | PERIODIC |
| Kind | DataFlowComponent |
| MAX Inst. | 1 |

### Activity definition

<table>
  <tr>
    <td rowspan="4">on_initialize</td>
    <td colspan="2">implemented</td>
    <tr>
      <td>Description</td>
      <td></td>
    </tr>
    <tr>
      <td>PreCondition</td>
      <td></td>
    </tr>
    <tr>
      <td>PostCondition</td>
      <td></td>
    </tr>
  </tr>
  <tr>
    <td>on_finalize</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>on_startup</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>on_shutdown</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td rowspan="4">on_activated</td>
    <td colspan="2">implemented</td>
    <tr>
      <td>Description</td>
      <td>初期化を行う。</td>
    </tr>
    <tr>
      <td>PreCondition</td>
      <td></td>
    </tr>
    <tr>
      <td>PostCondition</td>
      <td></td>
    </tr>
  </tr>
  <tr>
    <td rowspan="4">on_deactivated</td>
    <td colspan="2">implemented</td>
    <tr>
      <td>Description</td>
      <td>動的入力ポートを全て削除する。</td>
    </tr>
    <tr>
      <td>PreCondition</td>
      <td></td>
    </tr>
    <tr>
      <td>PostCondition</td>
      <td></td>
    </tr>
  </tr>
  <tr>
    <td rowspan="4">on_execute</td>
    <td colspan="2">implemented</td>
    <tr>
      <td>Description</td>
      <td>動的入出力ポートの追加と削除を行う。<br/>入力ポートのInPortManipに入力された文字列が数字のみの場合、その数字の番号の入力ポートがあればそのポートを削除する。<br/>入力ポートのInPortManipに入力された文字列に数字以外の文字が含まれていた場合、その文字数だけポートを追加する。<br/>動的入力ポートStringDataに入力があった場合、そのポートの名前、番号と文字列をコンソールに出力する。</td>
    </tr>
    <tr>
      <td>PreCondition</td>
      <td></td>
    </tr>
    <tr>
      <td>PostCondition</td>
      <td></td>
    </tr>
  </tr>
  <tr>
    <td rowspan="4">on_aborting</td>
    <td colspan="2">implemented</td>
    <tr>
      <td>Description</td>
      <td>動的入力ポートを全て削除する。</td>
    </tr>
    <tr>
      <td>PreCondition</td>
      <td></td>
    </tr>
    <tr>
      <td>PostCondition</td>
      <td></td>
    </tr>
  </tr>
  <tr>
    <td>on_error</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>on_reset</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>on_state_update</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>on_rate_changed</td>
    <td colspan="2"></td>
  </tr>
</table>

### InPorts definition

#### InPortManip

動的入出力ポートの追加と削除を行う。<br/>入力された文字列が数字のみの場合、その数字の番号の入力ポートがあればそのポートを削除する。<br/>入力された文字列に数字以外の文字が含まれていた場合、その文字数だけポートを追加する。

<table>
  <tr>
    <td>DataType</td>
    <td>RTC::TimedString</td>
    <td>TimedString</td>
  </tr>
  <tr>
    <td>IDL file</td>
    <td colspan="2">BasicDataType.idl</td>
  </tr>
  <tr>
    <td>Number of Data</td>
    <td colspan="2">データに依存</td>
  </tr>
  <tr>
    <td>Semantics</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Unit</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Occirrence frecency Period</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Operational frecency Period</td>
    <td colspan="2"></td>
  </tr>
</table>

#### StringData

コンソールに出力する文字列データ。

<table>
  <tr>
    <td>DataType</td>
    <td>RTC::TimedString</td>
    <td>DynamicInPort<TimedString></td>
  </tr>
  <tr>
    <td>IDL file</td>
    <td colspan="2">BasicDataType.idl</td>
  </tr>
  <tr>
    <td>Number of Data</td>
    <td colspan="2">データに依存</td>
  </tr>
  <tr>
    <td>Semantics</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Unit</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Occirrence frecency Period</td>
    <td colspan="2"></td>
  </tr>
  <tr>
    <td>Operational frecency Period</td>
    <td colspan="2"></td>
  </tr>
</table>


### OutPorts definition


### Service Port definition


### Configuration definition


## Demo

## Requirement

## Setup

### Windows

### Ubuntu

## Usage

## Running the tests

## LICENCE




## References




## Author

佐々木毅 (Takeshi SASAKI) <br/>sasaki-t(_at_)ieee.org
