#ifndef TANKACTOR_H
#define TANKACTOR_H


class TankActor
{
    public:
        TankActor();
        virtual ~TankActor();

    protected:
        void HorizontalMovement();
        void VerticalMovement();
    private:
};

#endif // TANKACTOR_H
