#include "player.h"

class Decorator: public AbstractPlayer {
    private:
        AbstractPlayer* component;
    public:
        Decorator(AbstractPlayer* component);
        virtual ~Decorator();
};
