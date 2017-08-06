#ifndef __PID_H_
#define __PID_H_


typedef struct
{
    float SampleTimeMs;
    float Kp;
    float Ki;
    float Kd;
    float ErrorSum;
    float Error;
    float ErrorOld;
    float Output;
    float Setpoint;
    float MaxLimit;
    float MinLimit;
    float LastInput;
} Pid_DataType;

void Pid_Init(Pid_DataType *pid, float _SampleRateMs, float Min, float Max);
float Pid_Handler(Pid_DataType *pid, float input);
void Pid_SetParameters(Pid_DataType *pid, float _p, float _i, float _d);
void Pid_SetSetpoint(Pid_DataType *pid, float setpoint);
float Pid_GetOutput(Pid_DataType *pid);
void Pid_AddToError(Pid_DataType *Pid, float in);

#endif /* __PID_H_ */
