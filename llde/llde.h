#ifndef LLDE_H
#define LLDE_H
#include "no.h"
#include <QString>

namespace Pedro
{
    class llde
    {
    private:
        int quantidadeElementos;
        no *inicio;
        no *fim;

    public:
        llde();
        bool estaVazia() const;
        void inserirInicio(int entrada);
        int acessarInicio() const;
        int retirarInicio();
        void inserirFim(int entrada);
        int acessarFim() const;
        int retirarFim();
        void inserirPosicao(int posicao, int entrada);
        int acessarPosicao(int posicao) const;
        int retirarPosicao(int posicao);
        QString obterDados() const;
        int getQuantidadeElementos() const;
        void inserirOrdenado(int entrada);
    };
}

#endif // LLDE_H
