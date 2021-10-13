bool float_equal(float lhs, float rhs) {
    return fabs(lhs - rhs) < 0.0001;
}

bool judge_backtrack(float *cards, int card_size) {
    if (card_size == 1) {
        return float_equal(cards[0], 24.0);
    }
    for (size_t i = 0; i < card_size; i ++) {
        for (size_t j = i + 1; j < card_size; j ++) {
            float number_i = cards[i], number_j = cards[j];
            cards[j] = cards[card_size - 1];
            cards[i] = number_i + number_j;
            if (judge_backtrack(cards, card_size - 1)) {
                return true;
            }
            cards[i] = number_i - number_j;
            if (judge_backtrack(cards, card_size - 1)) {
                return true;
            }
            cards[i] = number_j - number_i;
            if (judge_backtrack(cards, card_size - 1)) {
                return true;
            }
            cards[i] = number_i * number_j;
            if (judge_backtrack(cards, card_size - 1)) {
                return true;
            }
            if (!float_equal(number_j, 0)) {
                cards[i] = number_i / number_j;
                if (judge_backtrack(cards, card_size - 1)) {
                    return true;
                }
            }
            if (!float_equal(number_i, 0)) {
                cards[i] = number_j / number_i;
                if (judge_backtrack(cards, card_size - 1)) {
                    return true;
                }
            }
            cards[i] = number_i;
            cards[j] = number_j;
        }
    }
    return false;
}

bool judgePoint24(int* cards, int cardsSize) {
    float *float_cards = (float *)malloc(sizeof(float) * cardsSize);
    for (size_t i = 0; i < cardsSize; i ++) {
        float_cards[i] = (float)cards[i];
    }
    bool result = judge_backtrack(float_cards, cardsSize);
    free(float_cards);
    return result;
}
