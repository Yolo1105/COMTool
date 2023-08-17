# COMTool
XINYI COMTool Assist is a serial port testing debug tools written by VC

Features
-	Auto save of received data area when exit
-	Recall the latest AT command settings
-	Serial Port type connection support
  - Auto detection of serial ports, including available ports and unavailable ports
	- Auto reconnection support for accidentally offline
-	Plugin support
  -	Basic send/ Receive data with timestamp
  -	Clear received data area
  -	Record send history
  -	Cyclic send with scheduled delay
  -	Import/Export AT commands
  -	Unplug/offline warning & Plugin/online prompt
  -	Auto added “\r\n” format


1.	Port Settings
“Open Port” can be selected either by clicking the first option in the “Setting” menu or the first icon in the toolbar. Once the “Port Setting” interface is opened, users can view the available “Serial Port” and “Baud rate” and customize the expected settings. The selected settings will be confirmed by clicking “OK” button or canceled by clicking “Cancel” button. The default settings are “COM 1” and “9600”. If the serial port is successfully opened, the icon of “Opening Port” will be banned and turning grey and the icon of “Close Port” will be recovered, otherwise a message box will pop out to warn user.

“Close Port” can be selected either by clicking the second option in the “Setting” menu or the second icon in the toolbar. If the serial port is successfully closed, the icon of “Close Port” will be banned and turning grey and the icon of “Open Port” will be recovered, otherwise a message box will pop out to warn user.


1.1	Opening serial port can fail. Please check if 
1. The serial port has already been opened in other application. 
2. Baud rate is too high 
3. USB connection is unstable
1.2	If the serial port is not found, please cancel the “Port Setting” interface and try to open port again for refreshing
1.3	If the new serial port is connected, the system will automatically connect to the new port with default 9600 baud rate

2.	Send Setting
AT commands can be written in the text box and click on “Send”, “AT” or “Cycle” button to send messages. Any action of sending will automatically add the format “\r\n”
2.1 In the common area, user can type in AT command in the left textbox and click on the right “Send” button to send. Only one AT command will be sent for each time of click but if the button is frequently clicked, the receiving area may crash or increase the lock
2.2 In the common area, if the delay of cycle is completed and the “cycle” check box is selected, the AT command in the left textbox will be automatically send with the scheduled delay time by clicking the right “Send” button once. The sending process can be ended by clicking the “Cycle” checkbox again. 	
2.3 In the script area, user can type in AT command in any of the 15 textbox and click on the corresponding “AT” button on the right to send one AT command for each time and customize the delay sending time, if the delay sending time box is empty, the delay time will be regarded as 0ms
2.4 In the script area, user can type in AT command in any of the 15 textbox and click on “Select All” checkbox to select all the line that includes contents. The selected status can be canceled by clicking the checkbox again. User can click on the “Cycle” checkbox to execute every selected line of AT command, following the sequential order from up to down, regarding to their corresponding delay time of send. The sending process can be ended by clicking the “Cycle Send” checkbox again

3.	Clear Log
User can clear the log context in the receiving area by either clicking the third “Clear Log” button in the tool bar or clicking the “Clear Log” button from the “Setting” menu.

4.	Save Log
User can save the log context in the specific file path by either clicking the fourth “Save Log” button in the tool bar or clicking the “Save Log” button from the “Setting” menu. If the file is not saved successfully, a message box will pop out to warn user.

5.	Import AT
User can import their own AT command .ini file by either clicking the fifth “Import AT” button the in tool bar or clicking the “Import AT” button from the “Setting” menu. If the file is not imported successfully, a message box will pop out to warn user

6.	Export AT
User can export the customized AT command .ini file by either clicking the sixth “Export AT” button the in tool bar or clicking the “Export AT” button from the “Setting” menu. If the file is not exported successfully, a message box will pop out to warn user

