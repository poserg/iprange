struct {
    unsigned first;
    unsigned last;
    int line;
    //struct IPRange *next;
} IPRange;

struct {
    struct IPRange *ipr;
    struct Data *next;
    Data (IPRange val, Data *n=0) : ipr(val), next(n) {}
} Data;

struct {

    struct Data *head, *cur;

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
