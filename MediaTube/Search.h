#ifndef SEARCH_H
#define SEARCH_H
#include <iostream>
#include <string>
class Media;

class Search {
public:
    virtual ~Search() {}
    virtual bool matches(const Media* media) const = 0;
    virtual void print(std::ostream& ost) const = 0;
};

class O_Search : public virtual Search {
    std::string owner;
public:
    O_Search(const std::string& owner);
    bool matches(const Media* media) const override;
    void print(std::ostream& ost) const override;
    std::string getOwner() const;
};

class C_Search : public virtual Search {
    std::string category;
public:
    C_Search(const std::string& category);
    bool matches(const Media* media) const override;
    void print(std::ostream& ost) const override;
    std::string getCategory() const;
};

class OorC_Search : public O_Search, public C_Search {
public:
    OorC_Search(const std::string& owner, const std::string& category);
    bool matches(const Media* media) const override;
    void print(std::ostream& ost) const override;
};

std::ostream& operator<<(std::ostream& ost, const Search& search);

#endif