#ifndef KEYSENDER_HPP
#define KEYSENDER_HPP

#include <QObject>
#include <QInputEvent>
#include <QKeyEvent>
#include <QMouseEvent>

#include "Keysender/Keysender_api.h"

#ifdef Q_OS_LINUX
struct _XDisplay;
#endif

#ifdef Keysender_EXPORTS
#  define KEYSENDER_EXPORT Q_DECL_EXPORT
#else
#  define KEYSENDER_EXPORT Q_DECL_IMPORT
#endif


namespace keysender {
class KEYSENDER_EXPORT Keysender : public QObject
{
  Q_OBJECT

public:
  explicit Keysender(QObject *parent = nullptr);

  Keysender(const Keysender& other) = delete;
  Keysender& operator=(const Keysender& other) = delete;
  virtual ~Keysender();

public slots:
  bool send(const QEvent& event);
  bool keyPress(Qt::Key key, Qt::KeyboardModifiers modifiers=Qt::NoModifier);
  bool keyRelease(Qt::Key key, Qt::KeyboardModifiers modifiers=Qt::NoModifier);

  // To be implemented at a later date
  bool keyShortcutOverride(const QKeyEvent& event);
  bool shortcutEvent(const QShortcutEvent& event);
  bool mouseEvent(const QMouseEvent& event);
  bool wheelEvent(const QWheelEvent& event);
private /* members */:
  // This big array only exists because Qt doesn't declare Qt::Key as a Q_ENUM
  static std::array<Qt::Key, 439> QT_KEYS;
#ifdef Q_OS_LINUX
  _XDisplay* x11;
#endif
};
}
#endif // KEYSENDER_HPP
