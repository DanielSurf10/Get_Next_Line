define plist
	set var $n = $arg0
	while $n
		printf "%d ", $n->content
		set var $n = $n->next
	end
end
