======================================================================
             Colored output in standard Windows console
======================================================================

Standard Windows ``cmd`` does not support ANSI control sequences. This is
a little bit weird, in ancient DOS times Microsoft shipped the ANSI.sys
driver with the system.

This simple Python sample shows how to deal with Windows API in order
to get nice coloured output. The script uses ``ctypes`` library.
