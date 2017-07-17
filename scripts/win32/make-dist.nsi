# Copyright luoxiangyong, E-mail: solo_lxy@126.com
# https://github.com/sololxy/solo-apprunner.git
#
!include "MUI2.nsh"
!include "nsDialogs.nsh"
!include "winmessages.nsh"

ShowInstDetails show
RequestExecutionLevel user

!define VERSION "0.1.0"
!define APP_NAME "apprunner"

Name "${APP_NAME} ${VERSION}"
OutFile "${APP_NAME}-${VERSION}-Installer.exe"

BrandingText "${APP_NAME} v${VERSION}"

# User interface changes
var Checkbox

# Add the desktop checkbox to the final page.
Function desktopCheckbox
  ${NSD_CreateCheckbox} 120u 130u 100% 10u "Create &desktop shortcut"
  Pop $Checkbox
  SetCtlColors $Checkbox "" "ffffff"
FunctionEnd

# Create the desktop link only, if the desktop checkbox is active.
Function createDesktopLink
  ${NSD_GetState} $Checkbox $0
  ${If} $0 <> 0
    CreateShortCut "$DESKTOP\${APP_NAME}.lnk" "$INSTDIR\${APP_NAME}.exe"
  ${EndIf}
FunctionEnd

# Variable definitions used in installer pages
InstallDir "$LOCALAPPDATA\${APP_NAME}-${VERSION}"
!define AppStartMenuFolder "${APP_NAME} ${VERSION}"

# Page settings
# Note that we repurpose the checkboxes on the FinishPage
# in order to keep it simple.
!define MUI_DIRECTORYPAGE_TEXT_TOP "${APP_NAME} may be installed in any accessible \
directory, including a home folder or portable device. Please run as Administrator\
 to install for system-wide use."
!define MUI_FINISHPAGE_SHOWREADME
!define MUI_FINISHPAGE_SHOWREADME_TEXT "Create Start Menu folder and shortcut"
!define MUI_FINISHPAGE_SHOWREADME_FUNCTION AddToStartMenu
!define MUI_FINISHPAGE_RUN
!define MUI_FINISHPAGE_RUN_TEXT "Open ${APP_NAME} install folder"
!define MUI_FINISHPAGE_RUN_FUNCTION ShowInstallFolder

# Pages to show
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES

!define MUI_PAGE_CUSTOMFUNCTION_SHOW desktopCheckbox
!define MUI_PAGE_CUSTOMFUNCTION_LEAVE createDesktopLink
!insertmacro MUI_PAGE_FINISH

!insertmacro MUI_LANGUAGE "English"

# Add/Remove Programs entry
!define ARP "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APP_NAME} ${VERSION}"

Section "Dummy Section" SecDummy
    SetOutPath $INSTDIR
    #File /a /r "${APP_NAME}\*"
    File /a /r "*.exe"
    File /a /r "*.dll"
	CreateDirectory $INSTDIR\config
    File "/oname=config\config.xml" ".\config\config.xml"
    WriteUninstaller "$INSTDIR\Uninstall.exe"
    CreateShortcut "$INSTDIR\${APP_NAME}.lnk" "$INSTDIR\${APP_NAME}.exe"

    # ARP entries
    WriteRegStr HKCU "${ARP}" \
                 "DisplayName" "${APP_NAME} ${Version}"
    WriteRegStr HKCU "${ARP}" \
                 "Publisher" "The SoloTech"
    #WriteRegStr HKCU "${ARP}" \
    #             "DisplayIcon" "$INSTDIR\bin\julia.exe"
    WriteRegStr HKCU "${ARP}" \
                 "UninstallString" "$\"$INSTDIR\uninstall.exe$\""
    WriteRegStr HKCU "${ARP}" \
                 "QuietUninstallString" "$\"$INSTDIR\uninstall.exe$\" /S"
    #WriteRegDWORD HKCU "${ARP}" "EstimatedSize" "300"
    WriteRegDWORD HKCU "${ARP}" "NoModify" "1"
    WriteRegDWORD HKCU "${ARP}" "NoRepair" "1"
SectionEnd

Section "uninstall"
    Delete "$DESKTOP\${APP_NAME}.lnk"
    Delete "$INSTDIR\${APP_NAME}.lnk"
    DeleteRegKey HKCU "${ARP}"

    # Remove Start Menu entries
    Delete "$SMPROGRAMS\${AppStartMenuFolder}\${APP_NAME}.lnk"
    Delete "$SMPROGRAMS\${AppStartMenuFolder}\Uninstall.lnk"
    RMDir "$SMPROGRAMS\${AppStartMenuFolder}"

	Delete "$INSTDIR\*.exe"
	Delete "$INSTDIR\*.dll"
    Delete "$INSTDIR\uninstall.exe"
	Delete "$INSTDIR\config\*"

	RMDir "$INSTDIR\config"
    SetOutPath $DESKTOP
    RMDir "$INSTDIR"

SectionEnd

# Helper function to create Start Menu folder and shortcuts
Function AddToStartMenu
    CreateDirectory "$SMPROGRAMS\${AppStartMenuFolder}"
    CreateShortcut "$SMPROGRAMS\${AppStartMenuFolder}\${APP_NAME}-${VERSION}.lnk"\
                   "$INSTDIR\${APP_NAME}.lnk" "" "" "" "" "" "The SoloTech"
    CreateShortcut "$SMPROGRAMS\${AppStartMenuFolder}\Uninstall-${APP_NAME}-${VERSION}.lnk"\
                   "$instdir\Uninstall.exe"
FunctionEnd

# Opens the installation folder
Function ShowInstallFolder
    ExecShell "open" $INSTDIR
FunctionEnd
