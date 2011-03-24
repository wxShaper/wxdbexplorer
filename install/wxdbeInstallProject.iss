; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "wxDbExplorer"
#define MyAppVersion "0.1.0.934"
#define MyAppPublisher "kozlik-1"
#define MyAppURL "http://sourceforge.net/projects/wxdbexplorer/"
#define MyAppExeName "DatabaseExplorer.exe"

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{DDD9A125-7EE2-4AC4-9525-7A07242DE120}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={pf}\{#MyAppName}
DefaultGroupName={#MyAppName}
AllowNoIcons=yes
LicenseFile=LICENSE.txt
OutputBaseFilename=wxDbExplorerInstall
Compression=lzma
SolidCompression=yes

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked; OnlyBelowVersion: 0,6.1

[Files]
Source: "..\bin\gcc\DatabaseExplorer.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\bin\gcc\wxmsw28u_dblayer_sqlite_dbe.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "wxmsw28u_gcc_custom.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\bin\gcc\wxmsw28u_scintilla_dbe.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "..\bin\gcc\wxmsw28u_shapeframework_dbe.dll"; DestDir: "{app}"; Flags: ignoreversion
; NOTE: Don't use "Flags: ignoreversion" on any shared system files
Source: ..\bin\gcc\dataClass.ctmp; DestDir: {app}; Flags: IgnoreVersion; 
Source: ..\bin\gcc\dataClass.htmp; DestDir: {app}; Flags: IgnoreVersion; 

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{group}\{cm:UninstallProgram,{#MyAppName}}"; Filename: "{uninstallexe}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: quicklaunchicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, "&", "&&")}}"; Flags: nowait postinstall skipifsilent