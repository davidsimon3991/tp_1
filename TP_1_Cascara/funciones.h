#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

float numero_A();
/** \brief numero_A obtiene un numero ingresado por el usuario
 *
 * \param num guarda el numero ingresado
 * \return num devuelve el valor ingresado
 *
 */
float numero_B();
/** \brief numero_B obtiene un numero ingresado por el usuario
 *
 * \param num guarda el numero ingresado
 * \return num devuelve el valor ingresado
 *
 */

void sumar(float,float);
/** \brief sumar suma dos numeros que obtiene de numero_A y numero_B
 *
 * \param rdo obtiene el valor de la suma de x y
 * \param x tiene el valor de numero_A
 * \param y tiene el valor de numero_B
 * \return rdo devuelve el resultado
 *
 */

void restar(float,float);
/** \brief restar resta dos numeros que obtiene de numero_A y numero_B
 *
 * \param rdo obtiene el valor de la resta de x y
 * \param x tiene el valor de numero_A
 * \param y tiene el valor de numero_B
 * \return rdo devuelve el resultado
 *
 */
void dividir(float,float);
/** \brief dividir divide dos numeros que obtiene de numero_A y numero_B
 *
 * \param rdo obtiene el valor de la division entre x y
 * \param x tiene el valor de numero_A
 * \param y tiene el valor de numero_B
 * \return rdo y es 0 no hace la operacion y es 1 realiza la division
 *
 */
void multiplicar(float, float);
/** \brief multiplicar multiplica dos numeros que obtiene de numero_A y numero_B
 *
 * \param rdo obtiene el valor de la multiplicacion entre x y
 * \param x tiene el valor de numero_A
 * \param y tiene el valor de numero_B
 * \return rdo devuelve el resultado
 *
 */
void factoreo(int);
/** \brief factoreo hace la factorizacion de numero_A
 *
 * \param fact 1 valor que se multiplica con i
 * \param i obtiene el valor de numero_A
 * \return fact devuelve el factoreo
 *
 */
 void operaciones(float,float);
 /** \brief operaciones realiza la llamada a las cinco funciones anteriores pasando los valores de numero_A y numero_B
 *
 * \param x obtiene el valor de numero_A
 * \param y obtiene el valor de numero_B
 *
 */


#endif // FUNCIONES_H_INCLUDED
