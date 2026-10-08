// Test natif minimal : vérifie que la chaîne pio test -e native tourne.
#include <unity.h>

void setUp() {}
void tearDown() {}

static void test_chaine_native_fonctionne() {
    TEST_ASSERT_EQUAL_INT(2, 1 + 1);
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_chaine_native_fonctionne);
    return UNITY_END();
}
