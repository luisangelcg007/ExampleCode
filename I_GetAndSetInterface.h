/***********************************************************************/
/*                                                                     */
/*  FILE       :I_GetAndSetInterface.h                                 */
/*  DATE       :Sep 28th, 2021                                         */
/*  DESCRIPTION:Interface for set and get metoths                      */
/*                                                                     */
/*  CPU TYPE   :Arduino Due ATmega328P                                 */
/*  AUTHOR     :Luis Angel Cabral                                      */
/*                                                                     */
/*  PROJECT    :Code Example                                           */
/*  IDE        :Arduino IDE 1.8.16                                     */
/*                                                                     */
/***********************************************************************/

#ifndef I_GETANDSETINTERFACE_H_
#define I_GETANDSETINTERFACE_H_

enum StateEnumeration
{
    off = 0,
    on
};

struct I_GetAndSet_Api_t;

typedef struct
{
   const struct I_GetAndSet_Api_t *api;
} I_GetAndSet_t;

/*!
 * API for interacting with get and set.
 */
typedef struct I_GetAndSet_Api_t
{
   StateEnumeration (*GetState)(I_GetAndSet_t *_instance);
   void (*SetState)(I_GetAndSet_t *_instance, StateEnumeration state);
} I_GetAndSet_Api_t;

#endif
