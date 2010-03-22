#!/usr/bin/ruby

require "minitest/unit"
require "minitest/autorun"

class CounterTest < MiniTest::Unit::TestCase
    def test_can_create_c_object
        require "lib/counter"
        counter = Counter.new
        assert_instance_of( Counter, counter )
    end

    def test_calling_next_on_counter_object
        require "lib/counter"
        counter = Counter.new
        assert_equal( 1, counter.next )
    end
end
