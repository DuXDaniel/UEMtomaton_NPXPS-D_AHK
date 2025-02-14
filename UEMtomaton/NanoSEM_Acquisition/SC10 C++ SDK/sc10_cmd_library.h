#pragma once
#include <memory>
#include "stdafx.h"
using namespace std;

/// <summary>
/// list all the possible port on this computer.
/// </summary>
/// <param name="serialNo">port list returned string include serial number and device descriptor, separated by comma</param>
/// <returns>non-negative number: number of device in the list; negative number: failed.</returns>
DllExport int List(char *serialNo);

/// <summary>
/// list all the possible port on this computer.
/// </summary>
/// <param name="serialNo">port list returned string include serial number and device descriptor, seperated by comma</param>
/// <returns>non-negtive number: number of device in the list; negtive number : failed.</returns>
DllExport int GetPorts(char *serialNo);

/// <summary>
///  open port function.
/// </summary>
/// <param name="serialNo">serial number of the device to be opened, use GetPorts function to get exist list first.</param>
/// <param name="nBaud">bit per second of port</param>
/// <param name="timeout">set timeout value in (s)</param>
/// <returns> non-negtive number: hdl number returned successfully; negtive number : failed.</returns>
DllExport int Open(char* serialNo, int nBaud, int timeout);

/// <summary>
/// check opened status of port
/// </summary>
/// <param name="serialNo">serial number of the device to be checked.</param>
/// <returns> 0: port is not opened; 1 : port is opened.</returns>
DllExport int IsOpen(char *serialNo);

/// <summary>
/// close current opend port
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <returns> 0: success; negtive number : failed.</returns>
DllExport int Close(int hdl);

/// <summary>
/// <p>read string from device through opened port.</p>
/// <p>make sure the port was opened SUCCESSful before call this function.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="b">returned string buffer</param>
/// <param name="limit">
/// <p>ABS(limit): max length value of b buffer. </p>
/// <p>SIGN(limit) == 1 : wait RX event until time out value expired;</p>
/// <p>SIGN(limit) == -1: INFINITE wait event untill RX has data;</p>
/// </param>
/// <returns>non-negative number: size of actual read data in byte; negative number: failed.</returns>
DllExport int Read(int hdl, char *b, int limit);

/// <summary>
/// <p>write string to device through opened port.</p>
/// <p>make sure the port was opened SUCCESSful before call this function.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="b">input string</param>
/// <param name="size">size of string to be written.</param>
/// <returns>non-negative number: number of bytes written; negative number: failed.</returns>
DllExport int Write(int hdl, char *b, int size);

/// <summary>
/// <p>set command to device according to protocol in manual.</p>
/// <p>make sure the port was opened SUCCESSful before call this function.</p>
/// <p>make sure this is the correct device by checking the ID string before call this function.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="c">input command string</param>
/// <param name="size">lenth of input command string (<255)</param>
/// <returns>
/// <p>0: SUCCESS; negative number: failed.</p>
/// <p>0xEA: CMD_NOT_DEFINED;</p>
/// <p>0xEB: time out;</p>
/// <p>0xED: invalid string buffer;</p>
/// </returns>
DllExport int Set(int hdl, char *c, int size);

/// <summary>
/// <p>set command to device according to protocol in manual and get the return string.</p>
/// <p>make sure the port was opened SUCCESSful before call this function.</p>
/// <p>make sure this is the correct device by checking the ID string before call this function.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="c">input command string (<255)</param>
/// <param name="d">output string (<255)</param>
/// <returns>
/// <p>0: SUCCESS; negative number: failed.</p>
/// <p>0xEA: CMD_NOT_DEFINED;</p>
/// <p>0xEB: time out;</p>
/// <p>0xED: invalid string buffer;</p>
/// </returns>
DllExport int Get(int hdl, char *c, char *d);

/// <summary>
/// Purge the RX and TX buffer on port.
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="flag">
/// <p>FT_PURGE_RX: 0x01</p>
/// <p>FT_PURGE_TX: 0x02</p>
///</param>
/// <returns> 0: SUCCESS; negative number: failed.</returns>
DllExport int Purge(int hdl, int flag);

/// <summary>
/// <p>set SC10's timeout</p>
/// <p>make sure the port was opened successful before call this function.</p>
/// <p>make sure this is the correct device by checking the ID string before call this function.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="timeout">timeout</param>
/// <returns>
/// <p>0: success;</p>
/// </returns>
DllExport int SetTimeout(int hdl,int timeout);

/// <summary>
/// <p>set SC10's serial baud rate</p>
/// <p>make sure the port was opened successful before call this function.</p>
/// <p>make sure this is the correct device by checking the ID string before call this function.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="value">SC10 baud rate, 0 for 9.6k and 1 for 115k</param>
/// <returns>
/// <p>0: success;</p>
/// <p>0xEA: CMD_NOT_DEFINED;</p>
/// <p>0xEB: time out;</p>
/// </returns>
DllExport int SetBaudRate(int hdl,int value);

/// <summary>
/// <p>Set operating mode</p>
/// <p>make sure the port was opened successful before call this function.</p>
/// <p>make sure this is the correct device by checking the ID string before call this function.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="value">SC10 mode. 1-manual, 2-auto, 3-single, 4-repeat, 5-external gate</param>
/// <returns>
/// <p>0: success;</p>
/// <p>0xEA: CMD_NOT_DEFINED;</p>
/// <p>0xEB: time out;</p>
/// </returns>
DllExport int SetMode(int hdl,int value);

/// <summary>
/// <p>Enable/Disable the shutter</p>
/// <p>make sure the port was opened successful before call this function.</p>
/// <p>make sure this is the correct device by checking the ID string before call this function.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <returns>
/// <p>0: success;</p>
/// <p>0xEA: CMD_NOT_DEFINED;</p>
/// <p>0xEB: time out;</p>
/// </returns>
DllExport int ToggleEnable(int hdl);

/// <summary>
/// <p>set open duration</p>
/// <p>make sure the port was opened successful before call this function.</p>
/// <p>make sure this is the correct device by checking the ID string before call this function.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="value">shutter's open time in ms</param>
/// <returns>
/// <p>0: success;</p>
/// <p>0xEA: CMD_NOT_DEFINED;</p>
/// <p>0xEB: time out;</p>
/// </returns>
DllExport int SetOpenTime(int hdl,int value);

/// <summary>
/// <p>set close duration</p>
/// <p>make sure the port was opened successful before call this function.</p>
/// <p>make sure this is the correct device by checking the ID string before call this function.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="value">shutter's close time in ms</param>
/// <returns>
/// <p>0: success;</p>
/// <p>0xEA: CMD_NOT_DEFINED;</p>
/// <p>0xEB: time out;</p>
/// </returns>
DllExport int SetCloseTime(int hdl,int value);

/// <summary>
/// <p>set the trigger mode</p>
/// <p>make sure the port was opened successful before call this function.</p>
/// <p>make sure this is the correct device by checking the ID string before call this function.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="value">0:internal trigger mode,1:external trigger mode</param>
/// <returns>
/// <p>0: success;</p>
/// <p>0xEA: CMD_NOT_DEFINED;</p>
/// <p>0xEB: time out;</p>
/// </returns>
DllExport int SetTriggerMode(int hdl,int value);

/// <summary>
/// <p>Set Ex Trigger mode</p>
/// <p>make sure the port was opened successful before call this function.</p>
/// <p>make sure this is the correct device by checking the ID string before call this function.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="value">0:set the output trigger to follow the shutter output when the SH05 is connected, 1: force the trigger output to follow the controller output when an SH05 is equipped</param>
/// <returns>
/// <p>0: success;</p>
/// <p>0xEA: CMD_NOT_DEFINED;</p>
/// <p>0xEB: time out;</p>
/// </returns>
DllExport int SetExternalTriggerMode(int hdl,int value);

/// <summary>
/// <p>Set repeat count</p>
/// <p>make sure the port was opened successful before call this function.</p>
/// <p>make sure this is the correct device by checking the ID string before call this function.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="value">set the repeat count when in repeat mode, a value of 1-99</param>
/// <returns>
/// <p>0: success;</p>
/// <p>0xEA: CMD_NOT_DEFINED;</p>
/// <p>0xEB: time out;</p>
/// </returns>
DllExport int SetRepeatCount(int hdl,int value);

/// <summary>
/// <p>Get baud rate</p>
/// <p>make sure the port was opened successful before call this function.</p>
/// <p>make sure this is the correct device by checking the ID string before call this function.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="value">0: 9.6k, 1:115k</param>
/// <returns>
/// <p>0: success;</p>
/// <p>0xEA: CMD_NOT_DEFINED;</p>
/// <p>0xEB: time out;</p>
/// </returns>
DllExport int GetBaudRate(int hdl,int& value);

/// <summary>
/// <p>Get operating mode</p>
/// <p>make sure the port was opened successful before call this function.</p>
/// <p>make sure this is the correct device by checking the ID string before call this function.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="value">the mode value(1-5)</param>
/// <returns>
/// <p>0: success;</p>
/// <p>0xEA: CMD_NOT_DEFINED;</p>
/// <p>0xEB: time out;</p>
/// </returns>
DllExport int GetMode(int hdl,int& value);

/// <summary>
/// <p>Get State</p>
/// <p>make sure the port was opened successful before call this function.</p>
/// <p>make sure this is the correct device by checking the ID string before call this function.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="speed">0: the shutter is disabled, 1: enabled</param>
/// <returns>
/// <p>0: success;</p>
/// <p>0xEA: CMD_NOT_DEFINED;</p>
/// <p>0xEB: time out;</p>
/// </returns>
DllExport int GetEnableState(int hdl,int& value);

/// <summary>
/// <p>Get open duration</p>
/// <p>make sure the port was opened successful before call this function.</p>
/// <p>make sure this is the correct device by checking the ID string before call this function.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="value">the shutter's open time in ms</param>
/// <returns>
/// <p>0: success;</p>
/// <p>0xEA: CMD_NOT_DEFINED;</p>
/// <p>0xEB: time out;</p>
/// </returns>
DllExport int GetOpenTime(int hdl,int& value);

/// <summary>
/// <p>Get close duration</p>
/// <p>make sure the port was opened successful before call this function.</p>
/// <p>make sure this is the correct device by checking the ID string before call this function.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="value">the shutter's close time in ms</param>
/// <returns>
/// <p>0: success;</p>
/// <p>0xEA: CMD_NOT_DEFINED;</p>
/// <p>0xEB: time out;</p>
/// </returns>
DllExport int GetCloseTime(int hdl,int& value);

/// <summary>
/// <p>Get trigger mode</p>
/// <p>make sure the port was opened successful before call this function.</p>
/// <p>make sure this is the correct device by checking the ID string before call this function.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="value">0:internal trigger mode,1:external trigger mode</param>
/// <returns>
/// <p>0: success;</p>
/// <p>0xEA: CMD_NOT_DEFINED;</p>
/// <p>0xEB: time out;</p>
/// </returns>
DllExport int GetTriggerMode(int hdl,int& value);

/// <summary>
/// <p>Get Ex trigger mode</p>
/// <p>make sure the port was opened successful before call this function.</p>
/// <p>make sure this is the correct device by checking the ID string before call this function.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="value">external trigger mode</param>
/// <returns>
/// <p>0: success;</p>
/// <p>0xEA: CMD_NOT_DEFINED;</p>
/// <p>0xEB: time out;</p>
/// </returns>
DllExport int GetExternalTriggerMode(int hdl,int& value);

/// <summary>
/// <p>Return the repeat count</p>
/// <p>make sure the port was opened successful before call this function.</p>
/// <p>make sure this is the correct device by checking the ID string before call this function.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="value">repeat count, a value of 1-99</param>
/// <returns>
/// <p>0: success;</p>
/// <p>0xEA: CMD_NOT_DEFINED;</p>
/// <p>0xEB: time out;</p>
/// </returns>
DllExport int GetRepeatCount(int hdl,int& value);

/// <summary>
/// <p>Get closed state</p>
/// <p>make sure the port was opened successful before call this function.</p>
/// <p>make sure this is the correct device by checking the ID string before call this function.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="value">1: shutter is closed, 0: shutter is open</param>
/// <returns>
/// <p>0: success;</p>
/// <p>0xEA: CMD_NOT_DEFINED;</p>
/// <p>0xEB: time out;</p>
/// </returns>
DllExport int GetClosedState(int hdl,int& value);

/// <summary>
/// <p>Get interlock tripped</p>
/// <p>make sure the port was opened successful before call this function.</p>
/// <p>make sure this is the correct device by checking the ID string before call this function.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="value">1: interlock is tripped, otherwise 0</param>
/// <returns>
/// <p>0: success;</p>
/// <p>0xEA: CMD_NOT_DEFINED;</p>
/// <p>0xEB: time out;</p>
/// </returns>
DllExport int GetInterlockTripped(int hdl,int& value);

/// Undocumented Command
DllExport int GetStat(int hdl, char* d);

/// <summary>
/// <p>get the SC10 id</p>
/// <p>make sure the port was opened successful before call this function.</p>
/// <p>make sure this is the correct device by checking the ID string before call this function.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <param name="d">output string (<255)</param>
/// <returns>
/// <p>0: success;</p>
/// <p>0xEA: CMD_NOT_DEFINED;</p>
/// <p>0xEB: time out;</p>
/// </returns>
DllExport int GetId(int hdl,char* d);
DllExport int GetCommands(int hdl,char* d);

/// <summary>
/// <p>Save current baud rate and output trigger mode</p>
/// <p>make sure the port was opened SUCCESSful before call this function.</p>
/// <p>make sure this is the correct device by checking the ID string before call this function.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <returns>
/// <p>0: SUCCESS; negative number: failed.</p>
/// </returns>
DllExport int SaveSettings(int hdl);

/// <summary>
/// <p>Store configuration, save current settings(ex. mode, open time, close time) into EEPROM </p>
/// <p>make sure the port was opened SUCCESSful before call this function.</p>
/// <p>make sure this is the correct device by checking the ID string before call this function.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <returns>
/// <p>0: SUCCESS; negative number: failed.</p>
/// </returns>
DllExport int StoreConfiguration(int hdl);

/// <summary>
/// <p>Load configuration from EEPROM </p>
/// <p>make sure the port was opened SUCCESSful before call this function.</p>
/// <p>make sure this is the correct device by checking the ID string before call this function.</p>
/// </summary>
/// <param name="hdl">handle of port.</param>
/// <returns>
/// <p>0: SUCCESS; negative number: failed.</p>
/// </returns>
DllExport int LoadConfiguration(int hdl);
