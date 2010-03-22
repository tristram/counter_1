#include "ruby.h"

static VALUE next( VALUE self ) {
    return Qnil;
}

static VALUE counter;

void Init_counter() {
    counter = rb_define_class( "Counter", rb_cObject );
    rb_define_method( counter, "next", next, 0 );
}
