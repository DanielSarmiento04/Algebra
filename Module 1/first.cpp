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
        float coeficiente;
        float exponente;
        string variable;

    public:
        static Monomio division(Monomio monomio_1, Monomio monomio_2)
        {
            float coeficiente = monomio_1.getCoeficiente() / monomio_2.getCoeficiente();
            string variable_1 = monomio_1.getVariable();
            string variable_2 = monomio_2.getVariable();
            string variable;

            if (variable_1 == variable_2)
            {
                variable = variable_1;
                float exponente = monomio_1.getExponente() - monomio_2.getExponente();
                Monomio monomio(coeficiente, exponente, variable);
                return monomio;
            }
        }

        static Monomio mutiplicacion(Monomio monomio_1, Monomio monomio_2)
        {
            float coeficiente = monomio_1.getCoeficiente() * monomio_2.getCoeficiente();
            string variable_1 = monomio_1.getVariable();
            string variable_2 = monomio_2.getVariable();
            string variable;

            if (variable_1 == variable_2)
            {
                variable = variable_1;
                float exponente = monomio_1.getExponente() + monomio_2.getExponente();
                Monomio monomio(coeficiente, exponente, variable);
                return monomio;
            }
        }

        static Monomio suma(Monomio monomio_1, Monomio monomio_2)
        {
            float coeficiente = monomio_1.getCoeficiente() + monomio_2.getCoeficiente();
            string variable_1 = monomio_1.getVariable();
            string variable_2 = monomio_2.getVariable();
            string variable;
            float exponente_1 = monomio_1.getExponente();
            float exponente_2 = monomio_2.getExponente();

            if (variable_1 == variable_2 && exponente_1 == exponente_2)
            {
                variable = variable_1;
                Monomio monomio(coeficiente, exponente_1, variable);
                return monomio;
            }

            if (variable_1 == variable_2 && exponente_1 != exponente_2)
            {
                cout << "No se puede sumar los monomios" << endl;
            }
            // raise error 
        }

        static Monomio resta(Monomio monomio_1, Monomio monomio_2)
        {
            float coeficiente = monomio_1.getCoeficiente() - monomio_2.getCoeficiente();
            string variable_1 = monomio_1.getVariable();
            string variable_2 = monomio_2.getVariable();
            string variable;
            float exponente_1 = monomio_1.getExponente();
            float exponente_2 = monomio_2.getExponente();

            if (variable_1 == variable_2 && exponente_1 == exponente_2)
            {
                variable = variable_1;
                Monomio monomio(coeficiente, exponente_1, variable);
                return monomio;
            }

            if (variable_1 == variable_2 && exponente_1 != exponente_2)
            {
                cout << "No se puede restar los monomios" << endl;
            }
            // raise error
        }



        Monomio(float coeficiente, float exponente, string variable)
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

        float getCoeficiente()
        {
            return this->coeficiente;
        }
        float getExponente()
        {
            return this->exponente;
        }
        string getVariable()
        {
            return this->variable;
        }
        void setCoeficiente(float coeficiente)
        {
            this->coeficiente = coeficiente;
        }
        void setExponente(float exponente)
        {
            this->exponente = exponente;
        }
        void setVariable(string variable)
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
    Monomio monomio_1(8., 5., "x");
    Monomio monomio_2(-4., 5., "x");
    printf("multiplicacion");
    Monomio mult = Monomio::mutiplicacion(monomio_1, monomio_2);
    printf("division");
    Monomio div = Monomio::division(monomio_1, monomio_2);

    printf("suma");
    Monomio suma = Monomio::suma(monomio_1, monomio_2);

    printf("resta");
    Monomio resta = Monomio::resta(monomio_1, monomio_2);
    
    return 0;
}