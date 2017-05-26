#include "Keysender/Keysender.hpp"

#include <array>

#include <QEvent>
#include <QInputEvent>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QShortcutEvent>
#include <QtGlobal>

// Implement any Keysender methods that are platform-agnostic here

namespace keysender {

bool Keysender::send(const QEvent& event) {
  switch (event.type()) {
  case QEvent::KeyPress:
    return keyPress(static_cast<Qt::Key>(static_cast<const QKeyEvent&>(event).key()));
  case QEvent::KeyRelease:
    return keyRelease(static_cast<Qt::Key>(static_cast<const QKeyEvent&>(event).key()));
  case QEvent::ShortcutOverride:
    return keyShortcutOverride(static_cast<const QKeyEvent&>(event));

  case QEvent::MouseButtonDblClick:
  case QEvent::MouseButtonPress:
  case QEvent::MouseButtonRelease:
  case QEvent::MouseMove:
    return mouseEvent(static_cast<const QMouseEvent&>(event));
  case QEvent::Wheel:
    return wheelEvent(static_cast<const QWheelEvent&>(event));
  case QEvent::Shortcut:
    return shortcutEvent(static_cast<const QShortcutEvent&>(event));
  default:
    return false;
  }
}

std::array<Qt::Key, 439> Keysender::QT_KEYS {{
  Qt::Key_Escape,                // misc keys
  Qt::Key_Tab,
  Qt::Key_Backtab,
  Qt::Key_Backspace,
  Qt::Key_Return,
  Qt::Key_Enter,
  Qt::Key_Insert,
  Qt::Key_Delete,
  Qt::Key_Pause,
  Qt::Key_Print,               // print screen
  Qt::Key_SysReq,
  Qt::Key_Clear,
  Qt::Key_Home,                // cursor movement
  Qt::Key_End,
  Qt::Key_Left,
  Qt::Key_Up,
  Qt::Key_Right,
  Qt::Key_Down,
  Qt::Key_PageUp,
  Qt::Key_PageDown,
  Qt::Key_Shift,                // modifiers
  Qt::Key_Control,
  Qt::Key_Meta,
  Qt::Key_Alt,
  Qt::Key_CapsLock,
  Qt::Key_NumLock,
  Qt::Key_ScrollLock,
  Qt::Key_F1,                // function keys
  Qt::Key_F2,
  Qt::Key_F3,
  Qt::Key_F4,
  Qt::Key_F5,
  Qt::Key_F6,
  Qt::Key_F7,
  Qt::Key_F8,
  Qt::Key_F9,
  Qt::Key_F10,
  Qt::Key_F11,
  Qt::Key_F12,
  Qt::Key_F13,
  Qt::Key_F14,
  Qt::Key_F15,
  Qt::Key_F16,
  Qt::Key_F17,
  Qt::Key_F18,
  Qt::Key_F19,
  Qt::Key_F20,
  Qt::Key_F21,
  Qt::Key_F22,
  Qt::Key_F23,
  Qt::Key_F24,
  Qt::Key_F25,                // F25 .. F35 only on X11
  Qt::Key_F26,
  Qt::Key_F27,
  Qt::Key_F28,
  Qt::Key_F29,
  Qt::Key_F30,
  Qt::Key_F31,
  Qt::Key_F32,
  Qt::Key_F33,
  Qt::Key_F34,
  Qt::Key_F35,
  Qt::Key_Super_L,                 // extra keys
  Qt::Key_Super_R,
  Qt::Key_Menu,
  Qt::Key_Hyper_L,
  Qt::Key_Hyper_R,
  Qt::Key_Help,
  Qt::Key_Direction_L,
  Qt::Key_Direction_R,
  Qt::Key_Space,                // 7 bit printable ASCII
  Qt::Key_Any,
  Qt::Key_Exclam,
  Qt::Key_QuoteDbl,
  Qt::Key_NumberSign,
  Qt::Key_Dollar,
  Qt::Key_Percent,
  Qt::Key_Ampersand,
  Qt::Key_Apostrophe,
  Qt::Key_ParenLeft,
  Qt::Key_ParenRight,
  Qt::Key_Asterisk,
  Qt::Key_Plus,
  Qt::Key_Comma,
  Qt::Key_Minus,
  Qt::Key_Period,
  Qt::Key_Slash,
  Qt::Key_0,
  Qt::Key_1,
  Qt::Key_2,
  Qt::Key_3,
  Qt::Key_4,
  Qt::Key_5,
  Qt::Key_6,
  Qt::Key_7,
  Qt::Key_8,
  Qt::Key_9,
  Qt::Key_Colon,
  Qt::Key_Semicolon,
  Qt::Key_Less,
  Qt::Key_Equal,
  Qt::Key_Greater,
  Qt::Key_Question,
  Qt::Key_At,
  Qt::Key_A,
  Qt::Key_B,
  Qt::Key_C,
  Qt::Key_D,
  Qt::Key_E,
  Qt::Key_F,
  Qt::Key_G,
  Qt::Key_H,
  Qt::Key_I,
  Qt::Key_J,
  Qt::Key_K,
  Qt::Key_L,
  Qt::Key_M,
  Qt::Key_N,
  Qt::Key_O,
  Qt::Key_P,
  Qt::Key_Q,
  Qt::Key_R,
  Qt::Key_S,
  Qt::Key_T,
  Qt::Key_U,
  Qt::Key_V,
  Qt::Key_W,
  Qt::Key_X,
  Qt::Key_Y,
  Qt::Key_Z,
  Qt::Key_BracketLeft,
  Qt::Key_Backslash,
  Qt::Key_BracketRight,
  Qt::Key_AsciiCircum,
  Qt::Key_Underscore,
  Qt::Key_QuoteLeft,
  Qt::Key_BraceLeft,
  Qt::Key_Bar,
  Qt::Key_BraceRight,
  Qt::Key_AsciiTilde,

  Qt::Key_nobreakspace,
  Qt::Key_exclamdown,
  Qt::Key_cent,
  Qt::Key_sterling,
  Qt::Key_currency,
  Qt::Key_yen,
  Qt::Key_brokenbar,
  Qt::Key_section,
  Qt::Key_diaeresis,
  Qt::Key_copyright,
  Qt::Key_ordfeminine,
  Qt::Key_guillemotleft,        // left angle quotation mark
  Qt::Key_notsign,
  Qt::Key_hyphen,
  Qt::Key_registered,
  Qt::Key_macron,
  Qt::Key_degree,
  Qt::Key_plusminus,
  Qt::Key_twosuperior,
  Qt::Key_threesuperior,
  Qt::Key_acute,
  Qt::Key_mu,
  Qt::Key_paragraph,
  Qt::Key_periodcentered,
  Qt::Key_cedilla,
  Qt::Key_onesuperior,
  Qt::Key_masculine,
  Qt::Key_guillemotright,        // right angle quotation mark
  Qt::Key_onequarter,
  Qt::Key_onehalf,
  Qt::Key_threequarters,
  Qt::Key_questiondown,
  Qt::Key_Agrave,
  Qt::Key_Aacute,
  Qt::Key_Acircumflex,
  Qt::Key_Atilde,
  Qt::Key_Adiaeresis,
  Qt::Key_Aring,
  Qt::Key_AE,
  Qt::Key_Ccedilla,
  Qt::Key_Egrave,
  Qt::Key_Eacute,
  Qt::Key_Ecircumflex,
  Qt::Key_Ediaeresis,
  Qt::Key_Igrave,
  Qt::Key_Iacute,
  Qt::Key_Icircumflex,
  Qt::Key_Idiaeresis,
  Qt::Key_ETH,
  Qt::Key_Ntilde,
  Qt::Key_Ograve,
  Qt::Key_Oacute,
  Qt::Key_Ocircumflex,
  Qt::Key_Otilde,
  Qt::Key_Odiaeresis,
  Qt::Key_multiply,
  Qt::Key_Ooblique,
  Qt::Key_Ugrave,
  Qt::Key_Uacute,
  Qt::Key_Ucircumflex,
  Qt::Key_Udiaeresis,
  Qt::Key_Yacute,
  Qt::Key_THORN,
  Qt::Key_ssharp,
  Qt::Key_division,
  Qt::Key_ydiaeresis,

      // International input method support (X keycode - 0xEE00, the
      // definition follows Qt/Embedded 2.3.7) Only interesting if
      // you are writing your own input method

      // International & multi-key character composition
  Qt::Key_AltGr              ,
  Qt::Key_Multi_key          ,  // Multi-key character compose
  Qt::Key_Codeinput          ,
  Qt::Key_SingleCandidate    ,
  Qt::Key_MultipleCandidate  ,
  Qt::Key_PreviousCandidate  ,

      // Misc Functions
  Qt::Key_Mode_switch        ,  // Character set switch
      //Key_script_switch      ,  // Alias for mode_switch

      // Japanese keyboard support
  Qt::Key_Kanji              ,
  Qt::Key_Muhenkan           ,  // Cancel Conversion
      //Key_Henkan_Mode        ,  // Start/Stop Conversion
  Qt::Key_Henkan             ,  // Alias for Henkan_Mode
  Qt::Key_Romaji             ,  // to Romaji
  Qt::Key_Hiragana           ,  // to Hiragana
  Qt::Key_Katakana           ,  // to Katakana
  Qt::Key_Hiragana_Katakana  ,  // Hiragana/Katakana toggle
  Qt::Key_Zenkaku            ,  // to Zenkaku
  Qt::Key_Hankaku            ,  // to Hankaku
  Qt::Key_Zenkaku_Hankaku    ,  // Zenkaku/Hankaku toggle
  Qt::Key_Touroku            ,  // Add to Dictionary
  Qt::Key_Massyo             ,  // Delete from Dictionary
  Qt::Key_Kana_Lock          ,  // Kana Lock
  Qt::Key_Kana_Shift         ,  // Kana Shift
  Qt::Key_Eisu_Shift         ,  // Alphanumeric Shift
  Qt::Key_Eisu_toggle        ,  // Alphanumeric toggle
      //Key_Kanji_Bangou       ,  // Codeinput
      //Key_Zen_Koho           ,  // Multiple/All Candidate(s)
      //Key_Mae_Koho           ,  // Previous Candidate

      // Korean keyboard support
      //
      // In fact, many Korean users need only 2 keys, Key_Hangul and
      // Key_Hangul_Hanja. But rest of the keys are good for future.

  Qt::Key_Hangul             ,  // Hangul start/stop(toggle)
  Qt::Key_Hangul_Start       ,  // Hangul start
  Qt::Key_Hangul_End         ,
  Qt::Key_Hangul_Hanja       ,  // Start Hangul->Hanja Conversion
  Qt::Key_Hangul_Jamo        ,  // Hangul Jamo mode
  Qt::Key_Hangul_Romaja      ,  // Hangul Romaja mode
      //Key_Hangul_Codeinput   ,  // Hangul code input mode
  Qt::Key_Hangul_Jeonja      ,  // Jeonja mode
  Qt::Key_Hangul_Banja       ,  // Banja mode
  Qt::Key_Hangul_PreHanja    ,  // Pre Hanja conversion
  Qt::Key_Hangul_PostHanja   ,  // Post Hanja conversion
      //Key_Hangul_SingleCandidate  ,  // Single candidate
      //Key_Hangul_MultipleCandidate,  // Multiple candidate
      //Key_Hangul_PreviousCandidate,  // Previous candidate
  Qt::Key_Hangul_Special     ,  // Special symbols
      //Key_Hangul_switch      ,  // Alias for mode_switch

      // dead keys (X keycode - 0xED00 to avoid the conflict)
  Qt::Key_Dead_Grave         ,
  Qt::Key_Dead_Acute         ,
  Qt::Key_Dead_Circumflex    ,
  Qt::Key_Dead_Tilde         ,
  Qt::Key_Dead_Macron        ,
  Qt::Key_Dead_Breve         ,
  Qt::Key_Dead_Abovedot      ,
  Qt::Key_Dead_Diaeresis     ,
  Qt::Key_Dead_Abovering     ,
  Qt::Key_Dead_Doubleacute   ,
  Qt::Key_Dead_Caron         ,
  Qt::Key_Dead_Cedilla       ,
  Qt::Key_Dead_Ogonek        ,
  Qt::Key_Dead_Iota          ,
  Qt::Key_Dead_Voiced_Sound  ,
  Qt::Key_Dead_Semivoiced_Sound,
  Qt::Key_Dead_Belowdot      ,
  Qt::Key_Dead_Hook          ,
  Qt::Key_Dead_Horn          ,

      // multimedia/internet keys - ignored by default - see QKeyEvent c'tor
  Qt::Key_Back ,
  Qt::Key_Forward ,
  Qt::Key_Stop ,
  Qt::Key_Refresh ,
  Qt::Key_VolumeDown,
  Qt::Key_VolumeMute ,
  Qt::Key_VolumeUp,
  Qt::Key_BassBoost,
  Qt::Key_BassUp,
  Qt::Key_BassDown,
  Qt::Key_TrebleUp,
  Qt::Key_TrebleDown,
  Qt::Key_MediaPlay ,
  Qt::Key_MediaStop ,
  Qt::Key_MediaPrevious ,
  Qt::Key_MediaNext ,
  Qt::Key_MediaRecord,
  Qt::Key_MediaPause,
  Qt::Key_MediaTogglePlayPause,
  Qt::Key_HomePage ,
  Qt::Key_Favorites ,
  Qt::Key_Search ,
  Qt::Key_Standby,
  Qt::Key_OpenUrl,
  Qt::Key_LaunchMail ,
  Qt::Key_LaunchMedia,
  Qt::Key_Launch0 ,
  Qt::Key_Launch1 ,
  Qt::Key_Launch2 ,
  Qt::Key_Launch3 ,
  Qt::Key_Launch4 ,
  Qt::Key_Launch5 ,
  Qt::Key_Launch6 ,
  Qt::Key_Launch7 ,
  Qt::Key_Launch8 ,
  Qt::Key_Launch9 ,
  Qt::Key_LaunchA ,
  Qt::Key_LaunchB ,
  Qt::Key_LaunchC ,
  Qt::Key_LaunchD ,
  Qt::Key_LaunchE ,
  Qt::Key_LaunchF ,
  Qt::Key_MonBrightnessUp,
  Qt::Key_MonBrightnessDown,
  Qt::Key_KeyboardLightOnOff,
  Qt::Key_KeyboardBrightnessUp,
  Qt::Key_KeyboardBrightnessDown,
  Qt::Key_PowerOff,
  Qt::Key_WakeUp,
  Qt::Key_Eject,
  Qt::Key_ScreenSaver,
  Qt::Key_WWW,
  Qt::Key_Memo,
  Qt::Key_LightBulb,
  Qt::Key_Shop,
  Qt::Key_History,
  Qt::Key_AddFavorite,
  Qt::Key_HotLinks,
  Qt::Key_BrightnessAdjust,
  Qt::Key_Finance,
  Qt::Key_Community,
  Qt::Key_AudioRewind, // Media rewind
  Qt::Key_BackForward,
  Qt::Key_ApplicationLeft,
  Qt::Key_ApplicationRight,
  Qt::Key_Book,
  Qt::Key_CD,
  Qt::Key_Calculator,
  Qt::Key_ToDoList,
  Qt::Key_ClearGrab,
  Qt::Key_Close,
  Qt::Key_Copy,
  Qt::Key_Cut,
  Qt::Key_Display, // Output switch key
  Qt::Key_DOS,
  Qt::Key_Documents,
  Qt::Key_Excel,
  Qt::Key_Explorer,
  Qt::Key_Game,
  Qt::Key_Go,
  Qt::Key_iTouch,
  Qt::Key_LogOff,
  Qt::Key_Market,
  Qt::Key_Meeting,
  Qt::Key_MenuKB,
  Qt::Key_MenuPB,
  Qt::Key_MySites,
  Qt::Key_News,
  Qt::Key_OfficeHome,
  Qt::Key_Option,
  Qt::Key_Paste,
  Qt::Key_Phone,
  Qt::Key_Calendar,
  Qt::Key_Reply,
  Qt::Key_Reload,
  Qt::Key_RotateWindows,
  Qt::Key_RotationPB,
  Qt::Key_RotationKB,
  Qt::Key_Save,
  Qt::Key_Send,
  Qt::Key_Spell,
  Qt::Key_SplitScreen,
  Qt::Key_Support,
  Qt::Key_TaskPane,
  Qt::Key_Terminal,
  Qt::Key_Tools,
  Qt::Key_Travel,
  Qt::Key_Video,
  Qt::Key_Word,
  Qt::Key_Xfer,
  Qt::Key_ZoomIn,
  Qt::Key_ZoomOut,
  Qt::Key_Away,
  Qt::Key_Messenger,
  Qt::Key_WebCam,
  Qt::Key_MailForward,
  Qt::Key_Pictures,
  Qt::Key_Music,
  Qt::Key_Battery,
  Qt::Key_Bluetooth,
  Qt::Key_WLAN,
  Qt::Key_UWB,
  Qt::Key_AudioForward, // Media fast-forward
  Qt::Key_AudioRepeat, // Toggle repeat mode
  Qt::Key_AudioRandomPlay, // Toggle shuffle mode
  Qt::Key_Subtitle,
  Qt::Key_AudioCycleTrack,
  Qt::Key_Time,
  Qt::Key_Hibernate,
  Qt::Key_View,
  Qt::Key_TopMenu,
  Qt::Key_PowerDown,
  Qt::Key_Suspend,
  Qt::Key_ContrastAdjust,

  Qt::Key_LaunchG ,
  Qt::Key_LaunchH ,

  Qt::Key_TouchpadToggle,
  Qt::Key_TouchpadOn,
  Qt::Key_TouchpadOff,

  Qt::Key_MicMute,

  Qt::Key_Red,
  Qt::Key_Green,
  Qt::Key_Yellow,
  Qt::Key_Blue,

  Qt::Key_ChannelUp,
  Qt::Key_ChannelDown,

  Qt::Key_Guide   ,
  Qt::Key_Info    ,
  Qt::Key_Settings,

  Qt::Key_MicVolumeUp  ,
  Qt::Key_MicVolumeDown,

  Qt::Key_New     ,
  Qt::Key_Open    ,
  Qt::Key_Find    ,
  Qt::Key_Undo    ,
  Qt::Key_Redo    ,

  Qt::Key_MediaLast,

      // Keypad navigation keys
  Qt::Key_Select,
  Qt::Key_Yes,
  Qt::Key_No,

      // Newer misc keys
  Qt::Key_Cancel ,
  Qt::Key_Printer,
  Qt::Key_Execute,
  Qt::Key_Sleep  ,
  Qt::Key_Play   , // Not the same as Key_MediaPlay
  Qt::Key_Zoom   ,
      //Key_Jisho  , // IME: Dictionary key
      //Key_Oyayubi_Left, // IME: Left Oyayubi key
      //Key_Oyayubi_Right, // IME: Right Oyayubi key
  Qt::Key_Exit   ,

      // Device keys
  Qt::Key_Context1,
  Qt::Key_Context2,
  Qt::Key_Context3,
  Qt::Key_Context4,
  Qt::Key_Call,      // set absolute state to in a call (do not toggle state)
  Qt::Key_Hangup,    // set absolute state to hang up (do not toggle state)
  Qt::Key_Flip,
  Qt::Key_ToggleCallHangup,
  Qt::Key_VoiceDial,
  Qt::Key_LastNumberRedial,

  Qt::Key_Camera,
  Qt::Key_CameraFocus,

  Qt::Key_unknown,
}};

}
