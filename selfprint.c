/**
 * A program in C that prints out its own source code.
 *
 * Copyright (C) 2002, 2010 Stanislaw Findeisen <stf at eisenbits.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>

void print_special(const char s[])
{
    printf("\"");
    while (*s)
    {
        if (34 == (*s))
            printf("\\\"");
        else if (10 == (*s))
            printf("\\n");
        else if (92 == (*s))
            printf("\\\\");
        else if (37 == (*s))
            printf("%%");
        else
            printf("%c", *s);
        ++s;
    }
    printf("\"");
}

const char p[] = "void print_special(const char s[])\n{\n    printf(\"\\\"\");\n    while (*s)\n    {\n        if (34 == (*s))\n            printf(\"\\\\\\\"\");\n        else if (10 == (*s))\n            printf(\"\\\\n\");\n        else if (92 == (*s))\n            printf(\"\\\\\\\\\");\n        else if (37 == (*s))\n            printf(\"%%%%\");\n        else\n            printf(\"%%c\", *s);\n        ++s;\n    }\n    printf(\"\\\"\");\n}\n\n";

const char s[] = "int main()\n{\n    printf(\"/**\\n * A program in C that prints out its own source code.\\n *\\n * Copyright (C) 2002, 2010 Stanislaw Findeisen <stf at eisenbits.com>\\n *\\n * This program is free software: you can redistribute it and/or modify\\n * it under the terms of the GNU General Public License as published by\\n * the Free Software Foundation, either version 3 of the License, or\\n * (at your option) any later version.\\n *\\n * This program is distributed in the hope that it will be useful,\\n * but WITHOUT ANY WARRANTY; without even the implied warranty of\\n * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\\n * GNU General Public License for more details.\\n *\\n * You should have received a copy of the GNU General Public License\\n * along with this program.  If not, see <http://www.gnu.org/licenses/>.\\n */\\n\\n\");\n    printf(\"#include <stdio.h>\\n\\n\");\n    printf(p);\n    printf(\"const char p[] = \");\n    print_special(p);\n    printf(\";\\n\\nconst char s[] = \");\n    print_special(s);\n    printf(\";\\n\\n\");\n    printf(s);\n\n    return 0;\n}\n";

int main()
{
    printf("/**\n * A program in C that prints out its own source code.\n *\n * Copyright (C) 2002, 2010 Stanislaw Findeisen <stf at eisenbits.com>\n *\n * This program is free software: you can redistribute it and/or modify\n * it under the terms of the GNU General Public License as published by\n * the Free Software Foundation, either version 3 of the License, or\n * (at your option) any later version.\n *\n * This program is distributed in the hope that it will be useful,\n * but WITHOUT ANY WARRANTY; without even the implied warranty of\n * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n * GNU General Public License for more details.\n *\n * You should have received a copy of the GNU General Public License\n * along with this program.  If not, see <http://www.gnu.org/licenses/>.\n */\n\n");
    printf("#include <stdio.h>\n\n");
    printf(p);
    printf("const char p[] = ");
    print_special(p);
    printf(";\n\nconst char s[] = ");
    print_special(s);
    printf(";\n\n");
    printf(s);

    return 0;
}
