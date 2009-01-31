typedef struct IPRange {
    unsigned first;
    unsigned last;
    int line;
};

struct list {
    struct Data {
        IPRange ipr;
        Data* next;

        Data (IPRange val, Data* n=0) : ipr(val), next(n) {}
    };

    Data *head, *cur;

    list() { head=cur=0; }
    ~list() {
        for (Data *ptr = head, *n; ptr; ptr=n){
            n=ptr->next;
            delete ptr;
        }
    }

    void push_back (IPRange val) {
        if (!head) head = cur = new Data (val);
        else cur = cur->next = new Data(val);
    }
};
