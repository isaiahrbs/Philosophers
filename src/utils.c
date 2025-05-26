#include "philo.h"
#include "utils.h"

long	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	precise_usleep(long microseconds)
{
	long	start_time;
	long	current_time;

	start_time = get_current_time() * 1000;
	while (1)
	{
		current_time = get_current_time() * 1000;
		if (current_time - start_time >= microseconds)
			break;
		usleep(100); // Small sleep to prevent busy waiting
	}
}

void	safe_print(t_philo *philo, char *action)
{
	long	timestamp;

	pthread_mutex_lock(&philo->simu->print_mutex);
	if (!simulation_ended(philo->simu))
	{
		timestamp = get_current_time() - philo->simu->start_time;
		printf("%ld %d %s\n", timestamp, philo->id, action);
	}
	pthread_mutex_unlock(&philo->simu->print_mutex);
}

int	simulation_ended(t_simu *simu)
{
	int	result;

	pthread_mutex_lock(&simu->end_mutex);
	result = simu->simulation_end;
	pthread_mutex_unlock(&simu->end_mutex);
	return (result);
}

void	set_simulation_end(t_simu *simu)
{
	pthread_mutex_lock(&simu->end_mutex);
	simu->simulation_end = TRUE;
	pthread_mutex_unlock(&simu->end_mutex);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;

	// Skip whitespace
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
		   str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;

	// Handle sign
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}

	// Convert digits
	while (str[i] >= '0' && str[i] <= '9')
	{
		// Check for overflow
		if (result > (2147483647 - (str[i] - '0')) / 10)
		{
			if (sign == 1)
				return (2147483647);
			else
				return (-2147483648);
		}
		result = result * 10 + (str[i] - '0');
		i++;
	}

	return (result * sign);
}

int	is_valid_number(const char *str)
{
	int	i;

	if (!str || !*str)
		return (FALSE);

	i = 0;

	// Skip leading whitespace
	while (str[i] == ' ' || str[i] == '\t')
		i++;

	// Handle optional sign
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			return (FALSE); // Negative numbers not allowed
		i++;
	}

	// Check if there's at least one digit
	if (!str[i] || str[i] < '0' || str[i] > '9')
		return (FALSE);

	// Check all remaining characters are digits
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (FALSE);
		i++;
	}

	// Check for overflow
	if (ft_atoi(str) <= 0)
		return (FALSE);

	return (TRUE);
}
