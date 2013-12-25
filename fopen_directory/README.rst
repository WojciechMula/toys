Program test how C stdlib handles directories opened
with function ``fopen``.

Sample output::

	$ ./a.out ~
	testing '/home/wojtek'...
	fopen: Success [errno=0]
	fseek: Success [errno=0]
	fseek result: 0
	ftell: Success [errno=0]
	ftell result: 24576
	feof: Success [errno=0]
	feof result: 0 (EOF=no)
	fgetc: Is a directory [errno=21]
	fgetc result: -1 (EOF=yes)
	fread: Is a directory [errno=21]
	fread result: 0
	
System::

	$ gcc --version
	gcc version 4.7.2 (Debian 4.7.2-4)

	$ uname -a
	Linux cat.tac 3.2.0-3-686-pae #1 SMP Thu Jun 28 08:56:46 UTC 2012 i686 GNU/Linux
