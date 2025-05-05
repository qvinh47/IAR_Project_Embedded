int main() {
    // Bat clock cho GPIOC (bit 4 trong RCC_APB2ENR)
    *(unsigned int *)0x40021018 = 0x10U;

    // Cau hình PC13 làm output push-pull (mode=2MHz, cnf=00 ? 0b0010)
    // PC13 nam tai bits 23:20 trong CRH
    *(unsigned int *)0x40011004 = 0x00200000U;
    while (1) {
        // Ghi 0 vào ODR13 (bat LED)
        *(unsigned int *)0x4001100C = 0x00000000U;

        int counter = 0;
        while (counter < 1000000) {
            ++counter;
        }

        // Ghi 1 vào ODR13 (tat LED)
        *(unsigned int *)0x4001100C = 0x00002000U;
        counter = 0;
        while (counter < 1000000) {
            ++counter;
        }
    }
}
