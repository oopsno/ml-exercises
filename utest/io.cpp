#include <gtest/gtest.h>
#include <unistd.h>
#include <random>
#include <algorithm>
#include <fstream>
#include "mlexerices/io.hpp"

char tmp_templates[] = "/tmp/mlexe_utestXXXXXX";


TEST(IO, read_list) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<> std_nd(0, 1);
  std::vector<double> sample(64);
  std::generate(sample.begin(), sample.end(), [&]() {
    return std_nd(gen);
  });
  mkstemp(tmp_templates);
  std::string tmp_name = tmp_templates;
  std::ofstream of(tmp_name);
  of.precision(20);
  for (const double value : sample) {
    of << value << std::endl;
  }
  of.close();
  std::vector<double> read_in = read_list<double>(tmp_name);
  EXPECT_EQ(64, sample.size());
  EXPECT_EQ(64, read_in.size());
  for (int i = 0; i < 64; i++) {
    EXPECT_NEAR(sample[i], read_in[i], 0.00001);
  }
  remove(tmp_templates);
}

TEST(IO, read_content) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> int_id(0, 1024);
  std::string sample;
  for (int i = 0; i < 64; i++) {
    sample += std::to_string(int_id(gen));
    if (i != 63) {
      sample += "\n";
    }
  };
  mkstemp(tmp_templates);
  std::string tmp_name = tmp_templates;
  std::ofstream of(tmp_name);
  of << sample;
  of.flush();
  of.close();
  std::string content = read_content(tmp_name, "\n");
  EXPECT_EQ(sample, content);
  remove(tmp_templates);
}
