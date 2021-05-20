      #include <alchemy/timer.h> 
      #include <alchemy/task.h> 
      #include <stdio.h>
      #include <unistd.h>
      #define TASK_PRIO 99 /* Highest RT priority */ 
      #define TASK_MODE 0 /* No flags */ 
      #define TASK_STKSZ 0/* Stack size (use default one) */ 
      #define TASK_PERIOD 1000000 /* 100 usc period */ 
      RT_TASK task_desc; 
      void sampling_task (void *cookie) 
      { 
             int err = rt_task_set_periodic(NULL,TM_NOW, TASK_PERIOD);   
         while(1){
                   RTIME time1= rt_timer_read();
                 // rt_timer_spin(1000000);
            
                   RTIME time2 = rt_timer_read();
                   RTIME time3 = time2 - time1;
                   rt_printf("%lld\n", time3);
          
                  rt_task_wait_period(NULL);
                }
      } 
      int main (int argc, char *argv[]) 
      { 
           printf("ok");
          
           int err; 
             /* Disable paging for this program'smemory. */ 
             
             /* Create a real-time task */ 
             err =rt_task_create(&task_desc, 
             "task_desc", 
              TASK_STKSZ, 
              TASK_PRIO, 
              TASK_MODE); 
              if (!err) 
             /* If successfully created, start thetask. */ 
           rt_task_start(&task_desc,&sampling_task,NULL); 
              pause();
      } 
