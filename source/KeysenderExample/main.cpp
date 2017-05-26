#include <algorithm>
#include <cstdio>

#include <QCoreApplication>
#include <QCommandLineParser>
#include <QKeySequence>
#include <QtDebug>
#include <QDebug>
#include <QFile>
#include <QKeyEvent>

#include "Keysender/Keysender.hpp"
#include "Keysender/Keysender-version.h"

int main(int argc, char *argv[])
{
  QCoreApplication app(argc, argv);
  app.setApplicationName("KeysenderExample");
  app.setApplicationVersion(KEYSENDER_VERSION);
  QCommandLineParser parser;
  parser.setApplicationDescription(
    "Send keypresses to the windowing system"
  );

  parser.addOptions({
    {{"l", "list"}, "Lists the key codes currently available"}
  });
  parser.addPositionalArgument("keys", "The names of the keys to send to the windowing system", "<key>...");
  parser.addHelpOption();
  parser.addVersionOption();

  parser.process(app);

  QFile output;
  output.open(stdout, QIODevice::WriteOnly);

  QDebug out(&output);
  keysender::Keysender keysender;

  if (parser.isSet("list")) {
    // If we just want to list the key codes...
    auto keys = keysender.getSupportedKeys();

    if (keys.empty()) {
      qCritical() << "Couldn't determine which key codes can be used!";
      return 1;
    }

    auto keyList = keys.toList();
    std::sort(keyList.begin(), keyList.end());

    out.nospace();
    for (Qt::Key key : keyList) {
      // For each key, in sorted order...
      out << key << '\n';
    }

    output.flush();
    return 0;
  }


  QStringList sequences = parser.positionalArguments();
  if (sequences.empty()) {
    parser.showHelp(1);
  }



  for (const QString& s : sequences) {
    QKeySequence sequence(s);
    qInfo() << sequence;

    for (int i = 0; i < sequence.count(); ++i) {
      keysender.send(QKeyEvent(QKeyEvent::KeyPress, sequence[i], 0));
      keysender.send(QKeyEvent(QKeyEvent::KeyRelease, sequence[i], 0));
    }
  }

  return 0;
}
