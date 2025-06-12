#include <bits/stdc++.h>
using namespace std;
class book
{
public:
    string title;
    string author;
    book(string ti, string au, string is, int co, int to)
    {
        title = ti;
        author = au;
        isbn = is;
        copiesavailable = co;
        totalcopies = to;
    }
    book()
    {
        title = "UnknownTitle";
        author = "UnknownAuthor";
        isbn = "ISBN";
        copiesavailable = 0;
        totalcopies = 5;
    }
    book(book &c, string is)
    {
        title = c.title;
        author = c.author;
        isbn = is;
        copiesavailable = c.getcopies();
        totalcopies = c.gettotalcopies();
    }
    string getisbn()
    {
        return isbn;
    }
    int getcopies()
    {
        return copiesavailable;
    }
    int gettotalcopies()
    {
        return totalcopies;
    }
    void updatebook(int count)
    {
        if (totalcopies + count < 0)
        {
            cout << "Invalid request! Count becomes negative" << endl;
            ;
            return;
        }
        if (copiesavailable + count < 0)
        {
            cout << "Invalid request! Count becomes negative" << endl;
            ;
            return;
        }
        totalcopies += count;
        copiesavailable += count;
    }
    bool borrowbook()
    {
        if (copiesavailable > 0)
        {
            copiesavailable--;
            return true;
        }
        cout << "Invalid request! Copy of book not available" << endl;
        ;
        return false;
    }
    bool returnbook()
    {
        if (copiesavailable + 1 > totalcopies)
        {
            cout << "Invalid request! Copy of book exceeds total copies" << endl;
            ;
            return false;
        }
        copiesavailable++;
        return true;
    }
    void printdetails()
    {
        cout << title << " " << author << endl;
    }

private:
    string isbn;
    int copiesavailable;
    int totalcopies;
};
class member
{
public:
    string name;
    member(string id, string n, int limit)
    {
        name = n;
        memberid = id;
        borrowlimit = limit;
    }
    member(string id, string n)
    {
        name = n;
        memberid = id;
        borrowlimit = 3;
    }
    member()
    {

        borrowlimit = 3;
    }
    string getmemberid()
    {
        return memberid;
    }
    int getborrowlimit()
    {
        return borrowlimit;
    }
    map<string, int> get()
    {
        return borrowedbooks;
    }

    bool borrowbook(string isbn)
    {
        int ans = 0;
        for (auto &x : borrowedbooks)
        {
            ans += x.second;
        }
        if (ans >= borrowlimit)
        {
            cout << "Invalid request! Borrow limit exceeded" << endl;
            return false;
        }
        borrowedbooks[isbn]++;
        return true;
    }
    bool returnbook(string isbn)
    {
        if (borrowedbooks[isbn] <= 0)
        {
            cout << "Invalid request! Book not borrowed" << endl;
            return false;
        }
        borrowedbooks[isbn]--;
        return true;
    }

    void printdetails()
    {
        for (auto &x : borrowedbooks)
        {
            if (x.second != 0)
                cout << memberid << " " << name << " " << x.first << " " << x.second << endl;
        }
        return;
    }

private:
    string memberid;
    map<string, int> borrowedbooks;
    int borrowlimit;
};
class library
{
public:
    bool addbook(book &c)
    {
        string h = c.getisbn();
        for (auto &x : b)
        {
            if (h == x.getisbn())
            {
                cout << "Invalid request! Book with same isbn already exists" << endl;
                return false;
            }
        }
        b.push_back(c);

        return true;
    }
    bool registermemeber(member &c)
    {
        string h = c.getmemberid();

        for (auto &x : m)
        {
            if (h == x.getmemberid())
            {
                cout << "Invalid request! Member with same id already exists" << endl;
                return false;
            }
        }
        m.push_back(c);

        return true;
    }
    bool borrowbook(string memid, string isbn)
    {

        bool flag = false;
        bool mem = false;

        for (auto &x : b)
        {
            if (isbn == x.getisbn())
            {
                flag = x.borrowbook();
            }
        }

        if (flag)
        {

            for (auto &x : m)
            {
                if (x.getmemberid() == memid)
                {
                    mem = x.borrowbook(isbn);
                    if (mem)
                    {
                        return true;
                    }
                    else
                    {
                        for (auto &y : b)
                        {
                            if (y.getisbn() == isbn)
                            {
                                y.returnbook();
                                return false;
                            }
                        }
                    }
                }
            }
        }

        return flag;
    }
    bool returnbook(string memid, string isbn)
    {

        bool flag = false;
        bool mem = false;

        for (auto &x : b)
        {
            if (isbn == x.getisbn())
            {
                flag = x.returnbook();
            }
        }
        if (flag)
        {
            ;
            for (auto &x : m)
            {
                if (x.getmemberid() == memid)
                {
                    mem = x.returnbook(isbn);
                    if (mem)
                    {
                        return true;
                    }
                    else
                    {
                        for (auto &y : b)
                        {
                            if (y.getisbn() == isbn)
                            {
                                y.borrowbook();
                                return false;
                            }
                        }
                    }
                }
            }
        }

        return flag;
    }

    book getbook(string o)
    {
        book s;
        for (auto &x : b)
        {
            if (x.getisbn() == o)
            {
                s = x;
            }
        }
        return s;
    }
    void printmember(string o)
    {

        for (auto &x : m)
        {
            if (x.getmemberid() == o)
            {
                x.printdetails();
            }
        }
        return;
    }
    void updatebook(string o, int count)
    {

        for (auto &x : b)
        {
            if (x.getisbn() == o)
            {

                x.updatebook(count);
                return;
            }
        }
    }

    void printdetails()
    {
        for (auto &x : b)
        {
            cout << x.title << " " << x.author << " " << x.getcopies() << endl;
        }
        for (auto &x : m)
        {
            cout << x.getmemberid() << " " << x.name << endl;
        }
        return;
    }

private:
    vector<book> b;
    vector<member> m;
};
int main()
{
    library l;
    string s;

    int i = 500;
    while (s != "Done")
    {
        cin >> s;

        // cout << s << endl;
        if (s == "Book")
        {
            string k;
            cin >> k;

            if (k == "None")
            {
                book b1;
                l.addbook(b1);
            }
            else if (k == "ExistingBook")
            {
                string s1, s2;
                cin >> s1 >> s2;
                book d = l.getbook(s1);
                book c(d, s2);
                bool flag = l.addbook(c);
            }
            else
            {

                string au;
                string is;
                int co;
                int to;
                cin >> au >> is >> co >> to;

                book c(k, au, is, co, to);
                bool flag = l.addbook(c);
            }
        }
        else if (s == "UpdateCopiesCount")
        {
            string isbn;
            int newcount;
            cin >> isbn >> newcount;
            l.updatebook(isbn, newcount);
        }
        else if (s == "Member")
        {
            string k;
            cin >> k;
            if (k != "NoBorrowLimit")
            {
                string name;
                int borrowlimit;
                cin >> name >> borrowlimit;

                member m(k, name, borrowlimit);

                bool flag = l.registermemeber(m);
            }
            else
            {
                string memberid;
                string name;
                cin >> memberid >> name;
                member m(memberid, name);
                bool flag = l.registermemeber(m);
            }
        }
        else if (s == "Borrow")
        {
            string mem;
            string isbn;
            cin >> mem >> isbn;

            bool flag = l.borrowbook(mem, isbn);
        }
        else if (s == "Return")
        {

            string mem;
            string isbn;
            cin >> mem >> isbn;
            // l.printmember(mem);
            bool flag = l.returnbook(mem, isbn);
        }
        else if (s == "PrintBook")
        {
            string isbn;
            cin >> isbn;
            book c = l.getbook(isbn);
            c.printdetails();
        }
        else if (s == "PrintMember")
        {
            string memid;
            cin >> memid;
            l.printmember(memid);
        }
        else if (s == "PrintLibrary")
        {
            l.printdetails();
        }
        else
            break;
    }
    return 0;
}
