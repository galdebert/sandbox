import std.stdio;
 
int main(string[] argv)
{
    writeln("Hello D-World!");
	int i;
	writeln(&i);
	writeln((&i).sizeof);
    return 0;
}
