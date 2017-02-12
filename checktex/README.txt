Simple utility to check placing of curly brackets '{' '}' in a TeX file.

The program reports exact places (line, column) where not closed groups are
started -- TeX says only: "\end occured inside a group at [some] level".
The program finds also extra closing brackets -- TeX says only the line
where an error occured.

