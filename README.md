# Compositor Switcher for KDE

![Compositor Switcher for KDE](https://www.muratcileli.com/wp-content/uploads/static/compositor-switcher-for-kde.png "Logo Title Text 1")

Some of GNU/Linux window managers’ compositors causes screen tearing issues and FPS dropdowns in games. Compositor state can be controlled in different ways while running games / OpenGL applications.

### 1. KWin's Window Rules (Recommended)

KWin, can do this natively on a per-program or per-window basis, using its own rule engine.

Just right-click the title bar in the **Target Program** → **More actions** → **Special Application Settings**, and enjoy the many, many possibilities KWin offers. Blocking compositing for that whole program or that specific window is an option in the **"Appearance and Fixes"** tab.

Besides the user manually setting this things to their liking, well done programs can ask the WM to disable compositing for their particular windows, directly, and Plasma's window manager will obey such requests.

### 2. This Tool

If you think controlling compositor state by **process names** is easy than setting the KWin rules, you can use this tool alternatively.

### OK, looks good. How can I use?
Download latest release from "Releases" section. Make executable and run. Also you can build your own executable from sources. 

### Give me some process names!
* steam
* fs-uae
* fs-uae-launcher
* fs-uae-arcade
* mame
* dosbox
* smplayer
* Unity

