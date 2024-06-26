/*
  MIT License

  Copyright (c) 2022 Damiano Mazzella

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

#ifndef ARDUINO_PORTENTA_JERRYSCRIPT_H_
#define ARDUINO_PORTENTA_JERRYSCRIPT_H_

/******************************************************************************
 * INCLUDE
 ******************************************************************************/
#include <Arduino.h>
// #include <mbed.h>

#include "jerryscript-config.h"
#include "jerryscript.h"
#include "jerryscript-ext.h"


/**
 * Major version of Arduino_Portenta_JerryScript API.
 */
#define ARDUINO_PORTENTA_JERRYSCRIPT_API_MAJOR_VERSION 0

/**
 * Minor version of Arduino_Portenta_JerryScript API.
 */
#define ARDUINO_PORTENTA_JERRYSCRIPT_API_MINOR_VERSION 1

/**
 * Patch version of Arduino_Portenta_JerryScript API.
 */
#define ARDUINO_PORTENTA_JERRYSCRIPT_API_PATCH_VERSION 0

/*******************************************************************************
 *                                   Extra API                                 *
 ******************************************************************************/

#define JERRYXX_ARRAY_SIZE(array) ((jerry_length_t) (sizeof (array) / sizeof ((array)[0])))

#define JERRYXX_MAX_THREADS_NUMBER 20

#define JERRYXX_BOOL_CHK(f)  \
    do                       \
    {                        \
        if( !( ret = (f) ) ) \
        {                    \
          goto cleanup;      \
        }                    \
    } while( 0 )

#define JERRYXX_DECLARE_FUNCTION(f)                                         \
  jerry_value_t                                                             \
  js_##f (const jerry_call_info_t *call_info_p, /**< call information */    \
          const jerry_value_t args_p[], /**< function arguments */          \
          const jerry_length_t args_cnt) /**< number of function arguments */

#define JERRYXX_DEFINE_FUNCTION(f)                                           \
  jerry_value_t                                                              \
  js_##f (const jerry_call_info_t *call_info_p, /**< call information */     \
          const jerry_value_t args_p[], /**< function arguments */           \
          const jerry_length_t args_cnt); /**< number of function arguments */

#define JERRYXX_ON_ARGS_COUNT_THROW_ERROR_SYNTAX(c, msg) \
  if (c)                                                 \
  {                                                      \
    return jerry_throw_sz (JERRY_ERROR_SYNTAX, msg);     \
  }

#define JERRYXX_ON_TYPE_CHECK_THROW_ERROR_TYPE(c, msg) \
  if(c)                                                \
  {                                                    \
    return jerry_throw_sz (JERRY_ERROR_TYPE, msg);     \
  }

/**
 * Register a JavaScript property in the global object.
 *
 * @return true - if the operation was successful,
 *         false - otherwise.
 */
bool
jerryxx_register_global_property (const char *name_p, /**< name of the property */
                                  jerry_value_t value, /**< value of the property */
                                  bool free_value); /**< take ownership of the value */

jerry_value_t jerryxx_get_global_property(const char *name_p);
/**
 * Run JavaScript scheduler (user for switch setTimeout and setInterval threads).
 *
 * @return true - if the operation was successful,
 *         false - otherwise.
 */
bool
jerryxx_scheduler_yield(void);

/**
 * Cleanup scheduler thread in state Deleted.
 *
 * @return true - if the operation was successful,
 *         false - otherwise.
 */
bool
jerryxx_cleanup_scheduler_map(void);

/**
 * Register Extra API into JavaScript global object.
 *
 * @return true - if the operation was successful,
 *         false - otherwise.
 */
bool
jerryxx_register_extra_api(void);

/**
 * Javascript: setTimeout
 */
JERRYXX_DEFINE_FUNCTION(set_timeout);

/**
 * Javascript: clearTimeout
 */
JERRYXX_DEFINE_FUNCTION(clear_timeout);

/**
 * Javascript: setInterval
 */
JERRYXX_DEFINE_FUNCTION(set_interval);

/**
 * Javascript: clearInterval
 */
JERRYXX_DEFINE_FUNCTION(clear_interval);

/*******************************************************************************
 *                                  Arduino API                                *
 ******************************************************************************/

/**
 * Register Arduino API into JavaScript global object.
 *
 * @return true - if the operation was successful,
 *         false - otherwise.
 */
bool
jerryxx_register_arduino_api(void);

/**
 * Arduino: pinMode
 */
JERRYXX_DEFINE_FUNCTION(pin_mode);

/**
 * Arduino: digitalWrite
 */
JERRYXX_DEFINE_FUNCTION(digital_write);

/**
 * Arduino: digitalRead
 */
JERRYXX_DEFINE_FUNCTION(digital_read);

/**
 * Arduino: delay
 */
JERRYXX_DEFINE_FUNCTION(delay)

/**
 * Arduino: delayMicroseconds
 */
JERRYXX_DEFINE_FUNCTION(delay_microseconds);

/**
 * Arduino: micros
 */
JERRYXX_DEFINE_FUNCTION(micros);

/**
 * Arduino: millis
 */
JERRYXX_DEFINE_FUNCTION(millis);

/**
 * Arduino: randomSeed
 */
JERRYXX_DEFINE_FUNCTION(random_seed);

/**
 * Arduino: random
 */
JERRYXX_DEFINE_FUNCTION(random);

/**
 * Arduino: analogRead
 */
JERRYXX_DEFINE_FUNCTION(analog_read);

/**
 * Arduino: analogWrite
 */
JERRYXX_DEFINE_FUNCTION(analog_write);

/**
 * Arduino: analogReadResolution
 */
JERRYXX_DEFINE_FUNCTION(analog_read_resolution);

/**
 * Arduino: analogWriteResolution
 */
JERRYXX_DEFINE_FUNCTION(analog_write_resolution);

/**
 * Arduino: interrupts
 */
JERRYXX_DEFINE_FUNCTION(interrupts);

/**
 * Arduino: noInterrupts
 */
JERRYXX_DEFINE_FUNCTION(no_interrupts);

/**
 * Arduino: attachInterrupt
 */
JERRYXX_DEFINE_FUNCTION(attach_interrupt);

/**
 * Arduino: detachInterrupt
 */
JERRYXX_DEFINE_FUNCTION(detach_interrupt);

/**
 * Arduino: noTone
 */
JERRYXX_DEFINE_FUNCTION(no_tone);

/**
 * Arduino: pulseIn
 */
JERRYXX_DEFINE_FUNCTION(pulse_in);

/**
 * Arduino: pulseInLong
 */
JERRYXX_DEFINE_FUNCTION(pulse_in_long);

/**
 * Arduino: shiftIn
 */
JERRYXX_DEFINE_FUNCTION(shift_in);

/**
 * Arduino: shiftOut
 */
JERRYXX_DEFINE_FUNCTION(shift_out);

/**
 * Arduino: tone
 */
JERRYXX_DEFINE_FUNCTION(tone);

/**
 * Arduino: bit
 */
JERRYXX_DEFINE_FUNCTION(bit);

/**
 * Arduino: bitClear
 */
JERRYXX_DEFINE_FUNCTION(bit_clear);

/**
 * Arduino: bitRead
 */
JERRYXX_DEFINE_FUNCTION(bit_read);

/**
 * Arduino: bitSet
 */
JERRYXX_DEFINE_FUNCTION(bit_set);

/**
 * Arduino: bitWrite
 */
JERRYXX_DEFINE_FUNCTION(bit_write);

/**
 * Arduino: highByte
 */
JERRYXX_DEFINE_FUNCTION(high_byte);

/**
 * Arduino: lowByte
 */
JERRYXX_DEFINE_FUNCTION(low_byte);

/**
 * Arduino: constrain
 */
JERRYXX_DEFINE_FUNCTION(constrain);

/**
 * Arduino: map
 */
JERRYXX_DEFINE_FUNCTION(map);

/**
 * Arduino: sq
 */
JERRYXX_DEFINE_FUNCTION(sq);

/**
 * Arduino: isAlpha
 */
JERRYXX_DEFINE_FUNCTION(is_alpha);

/**
 * Arduino: isAlphaNumeric
 */
JERRYXX_DEFINE_FUNCTION(is_alpha_numeric);

/**
 * Arduino: isAscii
 */
JERRYXX_DEFINE_FUNCTION(is_ascii);

/**
 * Arduino: isControl
 */
JERRYXX_DEFINE_FUNCTION(is_control);

/**
 * Arduino: isDigit
 */
JERRYXX_DEFINE_FUNCTION(is_digit);

/**
 * Arduino: isGraph
 */
JERRYXX_DEFINE_FUNCTION(is_graph);

/**
 * Arduino: isHexadecimalDigit
 */
JERRYXX_DEFINE_FUNCTION(is_hexadecimal_digit);

/**
 * Arduino: isLowerCase
 */
JERRYXX_DEFINE_FUNCTION(is_lower_case);

/**
 * Arduino: isPrintable
 */
JERRYXX_DEFINE_FUNCTION(is_printable);

/**
 * Arduino: isPunct
 */
JERRYXX_DEFINE_FUNCTION(is_punct);

/**
 * Arduino: isSpace
 */
JERRYXX_DEFINE_FUNCTION(is_space);

/**
 * Arduino: isUpperCase
 */
JERRYXX_DEFINE_FUNCTION(is_upper_case);

/**
 * Arduino: isWhitespace
 */
JERRYXX_DEFINE_FUNCTION(is_whitespace);

#endif /* ARDUINO_PORTENTA_JERRYSCRIPT_H_ */