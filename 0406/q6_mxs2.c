#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXLEN 200005
#define ALPHA 26

typedef struct {
    int len, link;
    int next[ALPHA];
} State;

State st[MAXLEN * 2];
int sz, last;
long long totalSubstrings;

void saInit() {
    sz = 1;
    last = 0;
    totalSubstrings = 0;
    st[0].len = 0;
    st[0].link = -1;
    memset(st[0].next, -1, sizeof(st[0].next));
}

void saExtend(char c) {
    int ch = c - 'a';
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    memset(st[cur].next, -1, sizeof(st[cur].next));

    int p = last;
    while (p != -1 && st[p].next[ch] == -1) {
        st[p].next[ch] = cur;
        p = st[p].link;
    }

    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[ch];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            memcpy(st[clone].next, st[q].next, sizeof(st[q].next));
            st[clone].link = st[q].link;
            st[q].link = clone;
            st[cur].link = clone;
            while (p != -1 && st[p].next[ch] == q) {
                st[p].next[ch] = clone;
                p = st[p].link;
            }
        }
    }
    totalSubstrings += st[cur].len - st[st[cur].link].len;
    last = cur;
}

int main() {
    char s[MAXLEN];
    while (fgets(s, sizeof(s), stdin)) {
        saInit();
        for (int i = 0; s[i] && s[i] != '\n'; i++) {
            if (s[i] == '?') {
                printf("%lld\n", totalSubstrings);
            } else if (islower(s[i])) {
                saExtend(s[i]);
            }
        }
    }
    return 0;
}
