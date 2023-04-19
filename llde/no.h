#ifndef NO_H
#define NO_H

namespace Pedro
{
    class no
    {
    private:
        int dado;
        no *proximo;
        no *anterior;

    public:
        no();
        no(int);
        void setDado(int);
        int getDado() const;
        no *getProximo() const;
        void setProximo(no *newProximo);
        no *getAnterior() const;
        void setAnterior(no *newAnterior);
    };
}

#endif // NO_H
