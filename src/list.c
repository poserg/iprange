typedef struct _IPRange {
    unsigned first;
    unsigned last;
    int line;
} IPRange;

struct _Data {
    IPRange ipr;

    Data (IPRange val, Data* n=0) : ipr(val), next(n) {}
    Data* next = 0;
} Data;

struct _list {

    Data* head = 0;
    Data* cur = 0;

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
} list;
