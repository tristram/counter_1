#include "ruby.h"

void Init_counter() {
    rb_define_class( "Counter", rb_cObject );
}
