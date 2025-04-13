#include <iostream>

#include "base_opts.hpp"

class ProgOptions : public BaseOptions
{
public:
  /* default arguments */
  int jk_level = 1;
  int jk_type = 0;
  /* end arguments */

  ProgOptions() = default;
  ProgOptions(int argc, char **argv)
  {
    app.description(std::string(argv[0]) + " description");
    add_to_base_app(app);
    add_to_app(app);

    try {
      app.parse(argc, argv);
    } catch(const CLI::ParseError &e) {
      std::exit(app.exit(e));
    }
  }

protected:
  template <typename T>
  void add_to_app(T &app)
  {
    app.add_option("--jk_level", jk_level, "JK level")->capture_default_str();
    app.add_option("--jk_type", jk_type,  "JK type (0: spaced, 1: random)")->check(CLI::IsMember({0, 1}))->capture_default_str();
  }
};

int main(int argc, char **argv)
{
  ProgOptions opt(argc, argv);
  opt.print_args();

  return 0;
}
