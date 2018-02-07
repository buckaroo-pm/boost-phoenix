/*=============================================================================
    Copyright (c) 2005-2007 Dan Marsden
    Copyright (c) 2005-2007 Joel de Guzman
    Copyright (c) 2014      John Fletcher

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/phoenix.hpp>
#include <boost/phoenix/core.hpp>
#include <boost/phoenix/stl/algorithm/iteration.hpp>
#include <boost/core/lightweight_test.hpp>

#include <functional>
#include <vector>
#include <string>
#include <sstream>

namespace
{

    void for_each_test()
    {
        using boost::phoenix::for_each;
        using boost::phoenix::lambda;
        using boost::phoenix::val;
        using boost::phoenix::arg_names::arg1;

        std::vector<int> v;
        for (int i = 1; i < 10; i++)
           v.push_back(i);

        std::string test_str("(123456789)");
        std::ostringstream out;
        (
            out << val("("),
            for_each(arg1, lambda[out << arg1]),
            out << val(")")
        )(v);
        BOOST_TEST(out.str() == test_str);
        return;
    }

}

int main()
{
    for_each_test();
    boost::report_errors();
}
