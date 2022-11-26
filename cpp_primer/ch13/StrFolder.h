#ifndef STRFOLDER_H
#define STRFOLDER_H

#include "String.h"
#include <set>
using namespace std;

class Folder;

class Message {
    friend void swap(Message&, Message&);
    friend class Folder;
public:
    explicit Message(const String &str = " ") :
        contents(str) {}
    Message(const Message&);
    Message& operator = (const Message&);
    ~Message();
    Message(Message&&);
    Message& operator= (Message&&);
    Message& operator= (Message&&);

    void save(Folder&);
    void remove(Folder&);
    void debug_print();
private:
    String contents;
    std::set<Folder*> folders;
    void add_to_Folders(const Message&);
    void move_Folders(Message*);
    void remove_from_Folders();

    void addFldr(Folder *f) { folders.insert(f); }
    void remFldr(Folder *f) { folders.erase(f); }
};
void swap(Message&, Message&);

class Folder {
    friend void swap(Message&, Message&);
    friend class Message;
public:
    ~Folder();
    Folder(const Folder&);
    Folder& operator = (const Folder&);
    Folder(Folder&&);
    Folder& operator = (Folder&&);

    Folder() = default;

    void save(Message&);
    void remove(Message&);
    void debug_print();
private:
    set<Message*> msgs;
    void add_to_Messages(const Folder&);
    void remove_from_Msgs();
    void addMsg(Message *m) { msgs.insert(m); }
    void remMsg(Message *m) { msgs.erase(m); }
    void move_Messages(Folder*);
};

#endif