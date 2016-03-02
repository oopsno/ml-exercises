#ifndef ML_EXERCISES_IO_HPP
#define ML_EXERCISES_IO_HPP

#include <vector>
#include <string>
#include <fstream>
#include <sstream>

template<typename E>
std::vector<E> read_list(const std::string &filename,
                         const std::ios_base::openmode &mode = std::ios::in) {
  std::vector<E> elements;
  std::fstream is(filename, mode);
  E element;
  if (is.is_open()) {
    while (is >> element) {
      elements.push_back(element);
    }
  }
  is.close();
  return elements;
}

template<typename CharT=char>
std::basic_string<CharT> read_content(const std::string &filename,
                                      const std::string sep = "",
                                      const std::ios_base::openmode &mode = std::ios::in) {
  std::fstream is(filename, mode);
  std::basic_string<CharT> content;
  std::basic_string<CharT> line;
  if (is.is_open()) {
    while (is >> line) {
      content += line;
      if (sep.size() != 0 and not is.eof()) {
        content += sep;
      }
    }
    is.close();
  }
  return content;
}

#endif //ML_EXERCISES_IO_HPP