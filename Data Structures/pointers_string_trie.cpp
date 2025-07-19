struct string_trie {
    struct node {
        int f{};
        node *nxt[26]{};
    };

    node *rt{};

    void insert(node *&nd, string &s, int nxt = 0) {
        if (!nd) nd = new node();
        if (nxt < s.size())
            insert(nd->nxt[s[nxt] - 'a'], s, nxt + 1);
        nd->f++;
    }

    void erase(node *&nd, string &s, int nxt = 0) {
        if (nxt < s.size())
            erase(nd->nxt[s[nxt] - 'a'], s, nxt + 1);
        if (!--nd->f) delete nd, nd = 0;
    }

    int qry(node *&nd, string &s, int nxt = 0) {
        if (!nd) return 0;
        if (nxt == s.size()) return nd->f;
        return qry(nd->nxt[s[nxt] - 'a'], s, nxt + 1);
    }

    void insert(string &s) {
        insert(rt, s);
    }

    void erase(string &s) {
        erase(rt, s);
    }

    int qry(string &s) {
        return qry(rt, s);
    }
};
