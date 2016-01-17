#include <string>
#include <vector>

#include <stdlib.h>
#include <cstdint>
#include <cstdio>
#include <cstring>

const size_t NOT_FOUND = ~(size_t(0));

#include "strstr-stdstring.cpp"
#include "strstr64.cpp"

class Application final {

    std::string file_contents;
    std::vector<std::string> words;

public:
    Application(FILE* data, FILE* words) {
        
        file_contents = load_text_file(data);
        load_words(words);
    }

    int run() {

        for (const auto word: words) {

            const auto expected = file_contents.find(word);
            const auto result   = strstr64(file_contents.data(), file_contents.size(), word.c_str());

            if (result != expected) {
                printf("ERROR ('%s'): expected %ld, got %ld\n", word.c_str(), expected, result);
                return 1;
            }
        }

        return 0;
    }

private:
    std::string load_text_file(FILE* f) {

		fseek(f, -1, SEEK_END);
		auto size = ftell(f);
		fseek(f, 0, SEEK_SET);

        std::string data;
		data.resize(size);
		fread((void*)data.data(), size, 1, f);

		fclose(f);

        return data;
    }

    void load_words(FILE* f) {
        
        std::string word;

        while (true) {
            
            const int c = fgetc(f);
            if (feof(f)) {
                return;
            }

            if (isspace(c)) {

                if (!word.empty()) {
                    words.push_back(word);
                    word = "";
                }
            } else {
                
                word.push_back(c);
            }
        }
    }

};


int main(int argc, char* argv[]) {
	if (argc == 1) {
		puts("program input words");
		return EXIT_FAILURE;
	}

	FILE* file = fopen(argv[1], "rb");
	if (file == nullptr) {
		printf("File '%s' not found or can't be read\n", argv[1]);
		return EXIT_FAILURE;
	}

    FILE* words = fopen(argv[2], "rb");
	if (words == nullptr) {
		printf("File '%s' not found or can't be read\n", argv[2]);
		return EXIT_FAILURE;
	}

    Application app(file, words);

    return app.run();
}

