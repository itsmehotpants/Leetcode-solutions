class Robot {
public:
int x,y,dir,w,h,peri;
    Robot(int width, int height) {
        x=0,y=0;
        dir=1;
        w=width,h=height;
        peri = 2*(w+h-2);
    }
    //ENWS->1,0,3,2
    void step(int num) {
        if(num%peri==0 && x==0 && y==0) dir=2;
        num%=peri;
        while(num){
            int step;
            if(dir==1){
             step  = w-x-1;
             step =min(step,num);
             x+=step;
             num-=step;
            }
            else if(dir==0){
                step = h-1-y;
                step = min(step,num);
                y+=step;
                num-=step;
            }
              else if(dir==3){
                step = min(x,num);
                x-=step;
                num-=step;
            }
             else if(dir==2){
                step = min(y,num);
                y-=step;
                num-=step;
            }
            if(num) dir=(dir+3)%4;
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        if(dir == 1) return "East";
        if(dir == 0) return "North";
        if(dir == 3) return "West";

        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */