void uppercase(char *str) {
    char *curr;
    for (curr = str; *curr!= '\0'; curr++) {
        if ('a' <= *curr && *curr <= 'z') {
            *curr = 'A' + *curr - 'a';
        }
    }
}

void uppercase_goto_c(char *str) {
    char *curr;
    char c;
    char t;
    char ac;
    char zc; 
    char Ac;
    ac = 'a';
    zc = 'z';
    Ac = 'A';
    curr = str;
    c = curr;
loop:
    c = curr;
    if (c == '\0') goto after_loop;
    if (ac > c) goto after_if;
    if (c > zc) goto after_if;
    t = c - zc;
    t = Ac + t;
    *curr = t;
after_if:
    c = c + 1;
    goto loop;
after_loop:
    return;
}


