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

    def test_next_returns_consecutive_integers
        require "lib/counter"
        counter = Counter.new
        counter.next
        assert_equal( 2, counter.next )
    end

    def test_can_reset_counter
        require "lib/counter"
        counter = Counter.new
        counter.next
        counter.reset
        assert_equal( 1, counter.next )
    end
end
