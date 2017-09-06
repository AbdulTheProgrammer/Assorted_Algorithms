#include <vector>
template <typename P>
class PoundFIFO{
    private:
        struct Cat {
            P val;
            int order;
        };
        struct Dog {
            P val;
            int order;
        };
        int order;
        std::vector<Cat> catQ;
        std::vector<Dog> dogQ;
    public:
        int enqueueDog(P dog);
        int enqueueCat(P cat);
        P dequeueCat();
        P dequeueDog();
        P dequeueAny();
};
template <typename P>
int PoundFIFO<P>::enqueueDog(P dog) {
    Dog *d = new Dog();
    d->val = dog;
    d->order = order++;
    dogQ.push_back(d);
}
template <typename P>
int PoundFIFO<P>::enqueueCat(P cat){
    Cat *c = new Cat();
    c->val = cat;
    c->order = order++;
    catQ.push_back(c);
}
template <typename P>
P PoundFIFO<P>::dequeueCat() {
    if(catQ.empty())
        return NULL;
    Cat ret = catQ.back();
    catQ.pop_back();
    return ret->val;
}
template <typename P>
P PoundFIFO<P>::dequeueDog() {
    if(dogQ.empty())
        return NULL;
    Dog ret = catQ.back();
    catQ.pop_back();
    return ret->val;
}
template <typename P>
P PoundFIFO<P>::dequeueAny() {
    if(!catQ.size() && !dogQ.size())
        return NULL;
    if(!catQ.size())
        return dequeueDog();
    if(!dogQ.size())
        return dequeueCat();

    if(catQ.back()->order > dogQ.back()->order) {
        return dequeueDog();
    }
    return dequeueCat();
}

