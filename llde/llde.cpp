#include "llde.h"

Pedro::llde::llde():
    quantidadeElementos(0),
    inicio(0),
    fim(0)
{
}

bool Pedro::llde::estaVazia() const
{
    return !((bool)quantidadeElementos);
}

void Pedro::llde::inserirInicio(int entrada)
{
    try{
        no* aux = new no(entrada);
        if (estaVazia())
        {
            inicio = fim = aux;
            quantidadeElementos++;
            return;
        }
        inicio->setAnterior(aux);
        aux->setProximo(inicio);
        inicio = aux;
        quantidadeElementos++;
    }catch (std::bad_alloc &erro)
    {
        throw QString("Nao foi possivel alocar memoria - inserirInicio");
    }
}

QString Pedro::llde::obterDados()
{
    QString resultado = "";
    no* aux = inicio;
    for (int i = 0; i < quantidadeElementos; i++)
    {
        resultado += QString::number(aux->getDado()) + " ";
        aux = aux->getProximo();
    }
    if (estaVazia())
    {
        resultado = "(lista esta vazia)";
    }
    return resultado;
}

int Pedro::llde::getQuantidadeElementos()
{
    return quantidadeElementos;
}

int Pedro::llde::acessarInicio()
{
    if (estaVazia())
    {
        throw QString("Nao foi possivel acessar, lista vazia");
    }
    return inicio->getDado();
}

int Pedro::llde::retirarInicio()
{
    if (estaVazia())
    {
        throw QString("Nao foi possivel retirar, lista ja vazia");
    }
    int valor = inicio->getDado();
    no* aux = inicio;
    inicio = inicio->getProximo();
    if (inicio)
    {
        inicio->setAnterior(nullptr);
    }
    delete aux;
    quantidadeElementos--;
    return valor;
}
