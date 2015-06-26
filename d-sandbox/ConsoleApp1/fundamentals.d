module fundamentals;

// http://www.dsource.org/projects/tutorials/wiki/TutorialFundamentals


int addSquares(int a, int b)
{
    // A nested function in D has access to its enclosing function scope
    int squareIt()
    {
        return (a * a) + (b * b);
    }

    return squareIt();
}


void wait_for_user_input()
{
    writeln("Press enter (using 'std.c.stdio.getchar();' to wait) . . .");
    getchar();

    version (Windows)
    {
        writeln("Waiting again\n(using 'system(\"pause\");'):");
        system("pause");
    }

    version (linux)
    {
        writeln("Waiting again\n(using 'system(\"read -p \\\"Press enter to continue \\\" nothing;\");'):");
        system("read -p \"Press enter to continue \" nothing;");
    }
}

void strings()
{
    string s1 = r"c:\root\foo.exe"; // Wysiwyg Strings
    string s2 = "ab\n"; // Double Quoted Strings
    string s3 = q"(foo(xxx))"; // Delimited Strings
    string s4 = q{foo /*}*/}; // Token Strings - including comment
    string s5 = q{foo}; // Token Strings
}

