#include "TextWrap.h"
#include <gtest/gtest.h>

TEST(TextWrap, Constructor) {

    TextWrap textWrap{};
}

TEST(TextWrap, Constructor_PassNumberOfColmnsInConstructor) {

    TextWrap textWrap{14};
}

TEST(TextWrap, GetColumns) {

    TextWrap textWrap{14};
    EXPECT_EQ(14, textWrap.getColumns());
}

TEST(TextWrap, GetColumns_OtherNumberOfColumns) {

    TextWrap textWrap{7};
    EXPECT_EQ(7, textWrap.getColumns());
}

TEST(TextWrap, Wrap_EmptyString) {

    TextWrap textWrap{1};
    EXPECT_EQ("", textWrap.wrap(""));
}

TEST(TextWrap, Wrap_OneCharacterInOneColumn) {

    TextWrap textWrap{1};
    EXPECT_EQ("a", textWrap.wrap("a"));
}

TEST(TextWrap, Wrap_TwoCharacterInOneColumn) {

    TextWrap textWrap{1};
    EXPECT_EQ("a\nb", textWrap.wrap("ab"));
}

TEST(TextWrap, Wrap_FourCharacterInTwoColumns) {

    TextWrap textWrap{2};
    EXPECT_EQ("ab\ncd", textWrap.wrap("abcd"));
}

TEST(TextWrap, Wrap_SixCharacterInTwoColumns) {

    TextWrap textWrap{2};
    EXPECT_EQ("ab\ncd\nef", textWrap.wrap("abcdef"));
}

TEST(TextWrap, Wrap_SevenCharacterInTwoColumns) {

    TextWrap textWrap{2};
    EXPECT_EQ("ab\ncd\nef\ng", textWrap.wrap("abcdefg"));
}

TEST(TextWrap, Wrap_SevenCharacterInOneColumn) {

    TextWrap textWrap{1};
    EXPECT_EQ("a\nb\nc\nd\ne\nf\ng", textWrap.wrap("abcdefg"));
}

TEST(TextWrap, Wrap_EightCharacterInFiveColumns) {

    TextWrap textWrap{5};
    EXPECT_EQ("abcde\nfgh", textWrap.wrap("abcdefgh"));
}

TEST(TextWrap, Wrap_TwoWordsInFiveColumns) {

    TextWrap textWrap{5};
    EXPECT_EQ("abcd\nfgh", textWrap.wrap("abcd fgh"));
}

TEST(TextWrap, Wrap_ThreeWordsInEightColumns) {

    TextWrap textWrap{8};
    EXPECT_EQ("abc abc\nfgh", textWrap.wrap("abc abc fgh"));
}

TEST(TextWrap, Wrap_ThreeWordsInOneColumn) {

    TextWrap textWrap{1};
    EXPECT_EQ("a\nb\nc\na\nb\nc\nf\ng\nh", textWrap.wrap("abc abc fgh"));
}

TEST(TextWrap, Wrap_LongText_1) {

    TextWrap textWrap{50};
    EXPECT_EQ("Lorem ipsum dolor sit amet, consectetur adipiscing\nelit. Duis accumsan dignissim ante vel suscipit.\nAenean suscipit ex porttitor, lobortis eros non,\ncursus nunc. In consectetur, magna nec sodales\negestas, nisi felis tincidunt ipsum, et ornare\nmassa magna sit amet eros. Etiam bibendum eros\nviverra augue ultrices vehicula. Etiam risus\nlectus, rhoncus vitae odio eget, sagittis\nmalesuada nisl. Phasellus accumsan mi lorem, eget\nfinibus purus pulvinar nec. Aliquam consequat\nligula et maximus lobortis. In volutpat libero\nvitae eros gravida aliquet. Interdum et malesuada\nfames ac ante ipsum primis in faucibus. Fusce ac\nfelis sapien. Nulla at lacus non risus imperdiet\nbibendum sit amet molestie purus. Nunc quis rutrum\nest. Sed id nisl non tortor facilisis rhoncus.", textWrap.wrap("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis accumsan dignissim ante vel suscipit. Aenean suscipit ex porttitor, lobortis eros non, cursus nunc. In consectetur, magna nec sodales egestas, nisi felis tincidunt ipsum, et ornare massa magna sit amet eros. Etiam bibendum eros viverra augue ultrices vehicula. Etiam risus lectus, rhoncus vitae odio eget, sagittis malesuada nisl. Phasellus accumsan mi lorem, eget finibus purus pulvinar nec. Aliquam consequat ligula et maximus lobortis. In volutpat libero vitae eros gravida aliquet. Interdum et malesuada fames ac ante ipsum primis in faucibus. Fusce ac felis sapien. Nulla at lacus non risus imperdiet bibendum sit amet molestie purus. Nunc quis rutrum est. Sed id nisl non tortor facilisis rhoncus."));
}

TEST(TextWrap, Wrap_LongText_2) {

    TextWrap textWrap{80};
    EXPECT_EQ("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis accumsan dignissim\nante vel suscipit. Aenean suscipit ex porttitor, lobortis eros non, cursus nunc.\nIn consectetur, magna nec sodales egestas, nisi felis tincidunt ipsum, et ornare\nmassa magna sit amet eros. Etiam bibendum eros viverra augue ultrices vehicula.\nEtiam risus lectus, rhoncus vitae odio eget, sagittis malesuada nisl. Phasellus\naccumsan mi lorem, eget finibus purus pulvinar nec. Aliquam consequat ligula et\nmaximus lobortis. In volutpat libero vitae eros gravida aliquet. Interdum et\nmalesuada fames ac ante ipsum primis in faucibus. Fusce ac felis sapien. Nulla\nat lacus non risus imperdiet bibendum sit amet molestie purus. Nunc quis rutrum\nest. Sed id nisl non tortor facilisis rhoncus.", textWrap.wrap("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis accumsan dignissim ante vel suscipit. Aenean suscipit ex porttitor, lobortis eros non, cursus nunc. In consectetur, magna nec sodales egestas, nisi felis tincidunt ipsum, et ornare massa magna sit amet eros. Etiam bibendum eros viverra augue ultrices vehicula. Etiam risus lectus, rhoncus vitae odio eget, sagittis malesuada nisl. Phasellus accumsan mi lorem, eget finibus purus pulvinar nec. Aliquam consequat ligula et maximus lobortis. In volutpat libero vitae eros gravida aliquet. Interdum et malesuada fames ac ante ipsum primis in faucibus. Fusce ac felis sapien. Nulla at lacus non risus imperdiet bibendum sit amet molestie purus. Nunc quis rutrum est. Sed id nisl non tortor facilisis rhoncus."));
}

TEST(TextWrap, Wrap_LongText_3) {

    TextWrap textWrap{100};
    EXPECT_EQ("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis accumsan dignissim ante vel suscipit.\nAenean suscipit ex porttitor, lobortis eros non, cursus nunc. In consectetur, magna nec sodales\negestas, nisi felis tincidunt ipsum, et ornare massa magna sit amet eros. Etiam bibendum eros\nviverra augue ultrices vehicula. Etiam risus lectus, rhoncus vitae odio eget, sagittis malesuada\nnisl. Phasellus accumsan mi lorem, eget finibus purus pulvinar nec. Aliquam consequat ligula et\nmaximus lobortis. In volutpat libero vitae eros gravida aliquet. Interdum et malesuada fames ac ante\nipsum primis in faucibus. Fusce ac felis sapien. Nulla at lacus non risus imperdiet bibendum sit\namet molestie purus. Nunc quis rutrum est. Sed id nisl non tortor facilisis rhoncus.", textWrap.wrap("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis accumsan dignissim ante vel suscipit. Aenean suscipit ex porttitor, lobortis eros non, cursus nunc. In consectetur, magna nec sodales egestas, nisi felis tincidunt ipsum, et ornare massa magna sit amet eros. Etiam bibendum eros viverra augue ultrices vehicula. Etiam risus lectus, rhoncus vitae odio eget, sagittis malesuada nisl. Phasellus accumsan mi lorem, eget finibus purus pulvinar nec. Aliquam consequat ligula et maximus lobortis. In volutpat libero vitae eros gravida aliquet. Interdum et malesuada fames ac ante ipsum primis in faucibus. Fusce ac felis sapien. Nulla at lacus non risus imperdiet bibendum sit amet molestie purus. Nunc quis rutrum est. Sed id nisl non tortor facilisis rhoncus."));
}
