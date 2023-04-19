#include "llde.h"

Pedro::llde::llde() : quantidadeElementos(0),
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
    try
    {
        no *aux = new no(entrada);
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
    }
    catch (std::bad_alloc &erro)
    {
        throw QString("Nao foi possivel alocar memoria - inserirInicio");
    }
}

QString Pedro::llde::obterDados() const
{
    QString resultado = "";
    no *aux = inicio;
    for (int i = 0; i < quantidadeElementos; i++)
    {
        if (i == 0)
        {
            resultado += "|" + QString::number(aux->getDado()) + "|";
        }
        resultado += "-> |" + QString::number(aux->getDado()) + "|";
        aux = aux->getProximo();
    }
    if (estaVazia())
    {
        return "(lista esta vazia)";
    }
    return resultado;
}

int Pedro::llde::getQuantidadeElementos() const
{
    return quantidadeElementos;
}

int Pedro::llde::acessarInicio() const
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
    no *aux = inicio;
    inicio = inicio->getProximo();
    if (inicio)
    {
        inicio->setAnterior(nullptr);
    }
    else
    {
        delete inicio;
    }
    delete aux;
    quantidadeElementos--;
    return valor;
}

void Pedro::llde::inserirFim(int entrada)
{
    if (estaVazia())
    {
        inserirInicio(entrada);
        return;
    }
    try
    {
        no *aux = new no(entrada);
        fim->setProximo(aux);
        aux->setAnterior(fim);
        fim = aux;
        quantidadeElementos++;
    }
    catch (std::bad_alloc &erro)
    {
        throw QString("Nao foi possivel alocar memoria");
    }
}

int Pedro::llde::acessarFim() const
{
    if (estaVazia())
    {
        throw QString("Nao foi possivel acessar, lista vazia");
    }
    return fim->getDado();
}

int Pedro::llde::retirarFim()
{
    if (estaVazia())
    {
        throw QString("Nao foi possivel retirar, lista ja vazia");
    }
    no *aux = fim;
    int valor = fim->getDado();
    fim = fim->getAnterior();
    if (fim)
    {
        fim->setProximo(nullptr);
    }
    else
    {
        delete fim;
    }
    delete aux;
    quantidadeElementos--;
    return valor;
}

void Pedro::llde::inserirPosicao(int posicao, int entrada)
{
    if (posicao < 0 || posicao > quantidadeElementos)
    {
        throw QString("Posicao invalida");
    }
    if (estaVazia() || posicao == 0)
    {
        inserirInicio(entrada);
        return;
    }
    if (posicao == quantidadeElementos)
    {
        inserirFim(entrada);
        return;
    }
    try
    {
        no *novo = new no(entrada);
        no *aux = inicio;
        for (int i = 0; i < posicao; i++)
        {
            aux = aux->getProximo();
        }
        no *anterior = aux->getAnterior();
        anterior->setProximo(novo);
        novo->setAnterior(anterior);
        novo->setProximo(aux);
        aux->setAnterior(novo);
        quantidadeElementos++;
    }
    catch (std::bad_alloc &erro)
    {
        throw QString("Nao foi possivel alocar memoria");
    }
}

int Pedro::llde::acessarPosicao(int posicao) const
{
    if (posicao < 0 || posicao >= quantidadeElementos)
    {
        throw QString("Posicao invalida");
    }
    if (estaVazia())
    {
        throw QString("Lista vazia");
    }
    no *aux = inicio;
    for (int i = 0; i < posicao; i++)
    {
        aux = aux->getProximo();
    }
    return aux->getDado();
}

int Pedro::llde::retirarPosicao(int posicao)
{
    if (posicao < 0 || posicao >= quantidadeElementos)
    {
        throw QString("Posicao invalida");
    }
    if (estaVazia())
    {
        throw QString("Lista ja vazia");
    }
    if (posicao == quantidadeElementos - 1)
    {
        return retirarFim();
    }
    if (posicao == 0)
    {
        return retirarInicio();
    }
    no *aux = inicio;
    for (int i = 0; i < posicao; i++)
    {
        aux = aux->getProximo();
    }
    no *anterior = aux->getAnterior();
    no *proximo = aux->getProximo();
    anterior->setProximo(proximo);
    proximo->setAnterior(anterior);
    int valor = aux->getDado();
    delete aux;
    quantidadeElementos--;
    return valor;
}
