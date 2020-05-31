● The first argument, <input file> refers the source filename to be used for the
conversion and the second one, <outputfile>, refer the target XML filename. You
should take the input CSV filename as root node of the created XML.

● CSV2XML tool must take the following command line arguments:

○ -separator
defines separator between each datum (1=comma, 2=tab, 3=semicolon)

○ -opsys
defines the end of line character format (1=windows, 2=linux, 3=macos)

○ -h
print information to screen about how other arguments can be used.

● Usage of CSV2XML file must be as follows:
CSV2XML <"inputfile"> <"outputfile"> [-separator <"P1">][-opsys <"P2">][-h]

