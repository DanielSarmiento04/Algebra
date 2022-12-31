#include <math.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <list>

using namespace std;

class Monomio
{
    /*
        * Constructor de la clase Monomio
        * @param coeficiente: coeficiente del monomio
        * @param exponente: exponente del monomio
        * @param variable: variable del monomio
    */
    private:
        int coeficiente;
        int exponente;
        char variable;

    public:

        static Monomio mutiplicacion(Monomio monomio_1, Monomio monomio_2)
        {
            int coeficiente = monomio_1.getCoeficiente() * monomio_2.getCoeficiente();
            int exponente = monomio_1.getExponente() + monomio_2.getExponente();
            char variable = monomio_1.getVariable();

            Monomio monomio(coeficiente, exponente, variable);

            return monomio;
        }

        Monomio(int coeficiente, int exponente, char variable)
        {
            this->coeficiente = coeficiente;
            this->exponente = exponente;
            this->variable = variable;
            this->registroMonomio();
        }

        inline void registroMonomio()
        {
            // Register
            cout << "Se registro el siguiente monomio" << endl;
            this->print();
        };

        int getCoeficiente()
        {
            return this->coeficiente;
        }
        int getExponente()
        {
            return this->exponente;
        }
        char getVariable()
        {
            return this->variable;
        }
        void setCoeficiente(int coeficiente)
        {
            this->coeficiente = coeficiente;
        }
        void setExponente(int exponente)
        {
            this->exponente = exponente;
        }
        void setVariable(char variable)
        {
            this->variable = variable;
        }
        void print()
        {
            cout << this->coeficiente << this->variable << "^" << this->exponente << endl;
        }
};


int main()
{
    Monomio monomio_1(2, 3, 'x');
    Monomio monomio_2(2, -3, 'x');

    Monomio s = Monomio::mutiplicacion(monomio_1, monomio_2);


    return 0;
}